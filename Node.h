/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 12: Assignment
15 Nov 2024
Implements node structure for Red-Black Tree operations.
Stores data and manages node connections.
-------------------------------------------------- */

#ifndef NODE_H
#define NODE_H

// Forward declarations
class RedBlackTree;
class ProgramManager;

class Node {
public:

    // Constructor for new node initialization
    Node(int data) : data(data), color(RED), left(nullptr), right(nullptr), parent(nullptr) {}

private:

    // Friend class for tree operations
    friend class RedBlackTree;

    // Friend class for tree visualization
    friend class ProgramManager;

    int data;
    enum Color { RED, BLACK };
    Color color;
    Node* left;
    Node* right;
    Node* parent;
};

#endif