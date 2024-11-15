/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 12: Assignment
15 Nov 2024
Manages program execution and visualization.
Controls tree operations and display formatting.
-------------------------------------------------- */

#ifndef PROGRAMMANAGER_H
#define PROGRAMMANAGER_H

#include "Node.h" // Node operations module
#include "RedBlackTree.h" // Tree operations module
#include <string> // Text formatting module

using namespace std;

class ProgramManager {
public:

    // Constructor for program initialization
    ProgramManager();

    // Destructor for resource cleanup
    ~ProgramManager();

    // Display width constant
    static const int BORDER_LENGTH = 80;

private:
    RedBlackTree tree;

    // Core operation methods
    void run();
    void insertSequence();

    // Display methods
    void displayWelcomeMessage();
    void displayExitMessage();
    void displayTree();
    void displayNode(Node* node);
    void displaySubtree(Node* node, string prefix, string childPrefix);
};
#endif