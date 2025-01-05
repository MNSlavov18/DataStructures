#include <iostream>
#include <vector>
#include <unordered_set>

// --------------------------------------
// 1) Define a BST Node structure
// --------------------------------------
struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// --------------------------------------
// Helper function to print the BST in a
// sideways (rotated) fashion.
// --------------------------------------
void printTree(const Node* root, const std::string& prefix = "", bool isLeft = false) {
    if (!root) return;

    // Print the current node
    std::cout << prefix;

    // Show node label: either └── (left) or ┌── (right)
    std::cout << (isLeft ? "└──" : "┌──") << root->value << std::endl;

    // Extend the prefix string for children
    //   If we're printing the left child, add "|   ", otherwise add "    "
    std::string newPrefix = prefix + (isLeft ? "   " : "   ");

    // Print right child first (visually on top)
    printTree(root->right, newPrefix, false);
    // Print left child next (visually on bottom)
    printTree(root->left,  newPrefix, true);
}

// --------------------------------------
// 2) Insert into BST (recursive)
// --------------------------------------
Node* insertBST(Node* root, int val) {
    if (root == nullptr) {
        return new Node(val);
    }
    if (val < root->value) {
        root->left = insertBST(root->left, val);
    } else if (val > root->value) {
        root->right = insertBST(root->right, val);
    }
    // If val == root->value, do nothing (already in tree)
    return root;
}

// --------------------------------------
// 3) In-order traversal (L, Root, R)
//    to print in ascending order
// --------------------------------------
void inOrderTraversal(Node* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->value << " ";
    inOrderTraversal(root->right);
}

// --------------------------------------
// 4) Example main function
// --------------------------------------
int main() {
    // Given input (including duplicates)
    std::vector<int> input = {1, 2, 2, 8, 2, 12, 7, 3, 9, 7, 0, 0, 4, 9};

    // Step A: Remove duplicates while preserving order of appearance
    std::vector<int> uniqueValues;
    std::unordered_set<int> seen;
    uniqueValues.reserve(input.size());

    for (int x : input) {
        if (seen.find(x) == seen.end()) {
            // First time we see 'x'
            uniqueValues.push_back(x);
            seen.insert(x);
        }
        // Otherwise skip duplicates
    }

    // Step B: Build the BST, printing after each insertion
    Node* root = nullptr;
    std::cout << "Building the BST (print after each insert):\n\n";
    for (int val : uniqueValues) {
        // Insert val
        root = insertBST(root, val);

        // Print the tree to visualize its state
        std::cout << "After inserting " << val << ":\n";
        printTree(root);
        std::cout << std::endl;
    }

    // Step C: In-order traversal -> values in ascending order
    std::cout << "---------------------------------------------------\n";
    std::cout << "In-order traversal (ascending order): ";
    inOrderTraversal(root);
    std::cout << std::endl;

    // (Optional) You may want to clean up tree memory in a real application

    return 0;
}