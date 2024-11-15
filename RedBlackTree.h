/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 12: Assignment
15 Nov 2024
Implements self-balancing tree operations.
Maintains balanced structure through color rules.
-------------------------------------------------- */

#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H

#include "Node.h" // Node operations module

// Forward declarations
class ProgramManager;

class RedBlackTree {
public:

    // Constructor for empty tree creation
    RedBlackTree();

    // Destructor for tree cleanup
    ~RedBlackTree();

private:

    // Friend class for tree visualization
    friend class ProgramManager;

    Node* root;
    Node* NIL;

    // Tree manipulation methods
    void leftRotate(Node* currentNode);
    void rightRotate(Node* currentNode);
    void fixInsert(Node* insertedNode);
    void insert(int data);
};
#endif