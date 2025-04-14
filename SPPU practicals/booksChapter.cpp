#include <iostream>
#include <string>
#include <limits>
using namespace std;

// Node structure to represent each element in the tree
struct Node {
    string name;
    Node* firstChild;    // Points to the first child
    Node* nextSibling;   // Points to the next sibling

    // Constructor
    Node(string nodeName) {
        name = nodeName;
        firstChild = NULL;
        nextSibling = NULL;
    }
};

// Function to add a child node
void addChild(Node* parent, Node* child) {
    if (parent->firstChild == NULL) {
        // If parent has no children, add as first child
        parent->firstChild = child;
    } else {
        // If parent has children, add as sibling to last child
        Node* current = parent->firstChild;
        while (current->nextSibling != NULL) {
            current = current->nextSibling;
        }
        current->nextSibling = child;
    }
}

// Function to print the tree with proper indentation
void printTree(Node* root, int level = 0) {
    if (root == NULL) return;

    // Print indentation
    for (int i = 0; i < level; i++) {
        cout << "    ";
    }
    
    // Print current node
    cout << root->name << endl;

    // Print all children
    printTree(root->firstChild, level + 1);
    
    // Print all siblings
    printTree(root->nextSibling, level);
}

// Function to safely get integer input
int getIntInput(const string& prompt) {
    int value;
    while (true) {
        cout << prompt;
        if (cin >> value) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Please enter a number." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// Function to safely get string input
string getStringInput(const string& prompt) {
    string value;
    cout << prompt;
    getline(cin, value);
    return value;
}

// Function to add chapters
void addChapters(Node* book) {
    int numChapters = getIntInput("Enter the number of chapters: ");

    for (int i = 1; i <= numChapters; i++) {
        string chapterName = getStringInput("Enter name for Chapter " + to_string(i) + ": ");
        Node* chapter = new Node("Chapter " + to_string(i) + ": " + chapterName);
        addChild(book, chapter);

        // Add sections for this chapter
        int numSections = getIntInput("How many sections in Chapter " + to_string(i) + "? ");

        for (int j = 1; j <= numSections; j++) {
            string sectionName = getStringInput("Enter name for Section " + to_string(i) + "." + to_string(j) + ": ");
            Node* section = new Node("Section " + to_string(i) + "." + to_string(j) + ": " + sectionName);
            addChild(chapter, section);

            // Add subsections for this section
            int numSubsections = getIntInput("How many subsections in Section " + to_string(i) + "." + to_string(j) + "? ");

            for (int k = 1; k <= numSubsections; k++) {
                string subsectionName = getStringInput("Enter name for Subsection " + to_string(i) + "." + to_string(j) + "." + to_string(k) + ": ");
                Node* subsection = new Node("Subsection " + to_string(i) + "." + to_string(j) + "." + to_string(k) + ": " + subsectionName);
                addChild(section, subsection);
            }
        }
    }
}

int main() {
    string bookName = getStringInput("Enter the name of the book: ");
    
    // Create the book structure
    Node* book = new Node("Book: " + bookName);

    // Add chapters, sections, and subsections through user input
    addChapters(book);

    // Print the entire tree
    cout << "\nBook Structure Tree:\n" << endl;
    printTree(book);

    return 0;
}