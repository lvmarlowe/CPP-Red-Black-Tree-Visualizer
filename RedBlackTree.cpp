/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 12: Assignment
15 Nov 2024
Implements core Red-Black Tree functionality.
Contains balancing and modification operations.
-------------------------------------------------- */

#include <iostream> // Shows program output
#include <functional> // Enables function tools
#include "RedBlackTree.h" // Uses tree parts and functions

using namespace std;

// Sets up a tree with a special marker node
RedBlackTree::RedBlackTree() {

    // Makes the marker node with zero value
    NIL = new Node(0);

    // Marks it black and connects it to itself
    NIL->color = Node::Color::BLACK;
    NIL->left = NIL->right = NIL->parent = NIL;

    // Makes tree start empty with marker
    root = NIL;
}

// Removes all nodes from memory
RedBlackTree::~RedBlackTree() {
    if (root != NIL) {

        // Makes a function to remove nodes
        function<void(Node*)> deleteNodes = [&](Node* node) {
            if (node != NIL) {

                // Removes left and right sides first
                deleteNodes(node->left);
                deleteNodes(node->right);
                delete node;
            }
        };

        // Starts removing from the top
        deleteNodes(root);
    }

    // Removes the marker node last
    delete NIL;
}

// Moves nodes left to keep the tree balanced
void RedBlackTree::leftRotate(Node* currentNode) {

    // Picks right child to be the new parent
    Node* newParent = currentNode->right;

    // Shifts left group of nodes to new position
    currentNode->right = newParent->left;
    if (newParent->left != NIL) {

        // Links shifted nodes to new parent
        newParent->left->parent = currentNode;
    }

    // Sets up connections to upper tree
    newParent->parent = currentNode->parent;
    if (currentNode->parent == NIL) {

        // Makes new parent the top node
        root = newParent;
    }
    else if (currentNode == currentNode->parent->left) {

        // Links new parent to left spot
        currentNode->parent->left = newParent;
    }
    else {

        // Links new parent to right spot
        currentNode->parent->right = newParent;
    }

    // Finishes move by connecting last nodes
    newParent->left = currentNode;
    currentNode->parent = newParent;
}

// Moves nodes right to keep the tree balanced
void RedBlackTree::rightRotate(Node* currentNode) {

    // Make left child the new parent
    Node* newParent = currentNode->left;

    // Shifts right group of nodes to new position
    currentNode->left = newParent->right;
    if (newParent->right != NIL) {

        // Links shifted nodes to new parent
        newParent->right->parent = currentNode;
    }

    // Sets up connections to upper tree
    newParent->parent = currentNode->parent;
    if (currentNode->parent == NIL) {

        // Makes new parent the top node
        root = newParent;
    }
    else if (currentNode == currentNode->parent->right) {

        // Links new parent to right spot
        currentNode->parent->right = newParent;
    }
    else {

        // Links new parent to left spot
        currentNode->parent->left = newParent;
    }

    // Finishes move by connecting last nodes
    newParent->right = currentNode;
    currentNode->parent = newParent;
}

// Fixes color rules after adding a node
void RedBlackTree::fixInsert(Node* node) {
    while (node != root && node->parent->color == Node::Color::RED) {

        // Finds nearby family members
        Node* grandparent = node->parent->parent;
        bool isLeftChild = (node->parent == grandparent->left);
        Node* uncle = isLeftChild ? grandparent->right : grandparent->left;

        if (uncle->color == Node::Color::RED) {

            // Changes colors if uncle node is red
            node->parent->color = Node::Color::BLACK;
            uncle->color = Node::Color::BLACK;
            grandparent->color = Node::Color::RED;

            // Moves up to check next group
            node = grandparent;
        }
        else {

            // Handles triangle pattern with black uncle node
            if (node == (isLeftChild ? node->parent->right : node->parent->left)) {

                // Straightens out the pattern
                node = node->parent;
                isLeftChild ? leftRotate(node) : rightRotate(node);
            }

            // Fixes straight pattern with black uncle node
            node->parent->color = Node::Color::BLACK;
            grandparent->color = Node::Color::RED;

            // Shifts nodes to fix pattern
            isLeftChild ? rightRotate(grandparent) : leftRotate(grandparent);
        }
    }
    // Keeps top node black
    root->color = Node::Color::BLACK;
}

// Adds new number and keeps tree balanced
void RedBlackTree::insert(int data) {

    // Makes new red node with marker children
    Node* newNode = new Node(data);
    newNode->left = newNode->right = NIL;

    // Finds spot for new number
    Node* parent = NIL;
    Node* current = root;
    while (current != NIL) {
        parent = current;
        current = (data < current->data) ? current->left : current->right;
    }

    // Links new node to its parent
    newNode->parent = parent;

    if (parent == NIL) {

        // Makes new node the top if tree empty
        root = newNode;
    }
    else if (data < parent->data) {

        // Puts smaller numbers on left
        parent->left = newNode;
    }
    else {

        // Puts bigger numbers on right
        parent->right = newNode;
    }

    // Fixes colors and balance
    fixInsert(newNode);
}