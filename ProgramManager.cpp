/* LV Marlowe
SDEV-345: Data Structures & Algorithms
Week 12: Assignment
15 Nov 2024
Handles display and control of the Red-Black Tree program.
Manages user interface and program flow execution.
-------------------------------------------------- */

#include <iostream> // Shows program output
#include "ProgramManager.h" // Uses program functions

using namespace std;

// Creates border line of specified character
string createBorder(char symbol) {
    string border;
    for (int i = 0; i < ProgramManager::BORDER_LENGTH; i++) {
        border += symbol;
    }
    return border;
}

// Creates program and starts execution
ProgramManager::ProgramManager() {
    run();
}

// Cleans up program resources
ProgramManager::~ProgramManager() {
}

// Runs main program sequence
void ProgramManager::run() {
    displayWelcomeMessage();
    insertSequence();
    displayTree();
    displayExitMessage();
}

// Shows program introduction and purpose
void ProgramManager::displayWelcomeMessage() {
    cout << createBorder('=') << "\n"
        << "Red-Black Tree Visualizer\n"
        << createBorder('-') << "\n"
        << "This program shows how a self-balancing tree works by\n"
        << "using different colored nodes and automatic adjustments.\n"
        << createBorder('=') << "\n\n";
}

// Adds test numbers to tree
void ProgramManager::insertSequence() {
    const int values[] = { 30, 28, 21, 11, 17, 4 };
    for (int value : values) {
        tree.insert(value);
    }
}

// Shows details of single node
void ProgramManager::displayNode(Node* node) {
    if (node == tree.NIL) {
        cout << "NIL [BLACK]";
        return;
    }
    cout << node->data << " [" << (node->color == Node::Color::RED ? "RED" : "BLACK") << "]";
}

// Creates visual tree structure
void ProgramManager::displaySubtree(Node* node, string prefix, string childPrefix) {
    cout << prefix;
    displayNode(node);
    cout << '\n';
    if (node != tree.NIL) {
        string branchPrefix = childPrefix + "+-- ";
        string nextLevelPrefix = childPrefix + "|   ";
        string lastBranchPrefix = childPrefix + "    ";
        displaySubtree(node->left, branchPrefix, nextLevelPrefix);
        displaySubtree(node->right, branchPrefix, lastBranchPrefix);
    }
}

// Shows complete tree visualization
void ProgramManager::displayTree() {
    if (tree.root == tree.NIL) {
        cout << "Empty tree\n";
        return;
    }
    displaySubtree(tree.root, "", "");
}

// Shows exit message and status
void ProgramManager::displayExitMessage() {
    cout << "\n" << createBorder('=') << "\n"
        << "Exiting program.\n"
        << createBorder('-') << "\n"
        << "Thank you for using the Red-Black Tree Visualizer.\n"
        << createBorder('=') << "\n";
}