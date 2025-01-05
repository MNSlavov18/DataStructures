#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

// Функция за вмъкване на елемент в двоичното дърво за търсене
Node* insertBST(Node* root, int value) {
    // Ако сме попаднали на празно място, създаваме нов възел
    if (root == nullptr) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->left = newNode->right = nullptr;
        return newNode;
    }

    // Ако стойността е по-малка от тази на текущия възел, отиваме в лявото поддърво
    if (value < root->data) {
        root->left = insertBST(root->left, value);
    }
    // В противен случай (value >= root->data) – в дясното
    else {
        root->right = insertBST(root->right, value);
    }
    return root;
}

// Инфиксно (in-order) обхождане: ляво поддърво -> корен -> дясно поддърво
void inOrder(Node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }
}

int main() {
    setlocale(LC_ALL, ""); // За коректно изписване на кирилица при нужда
    Node* root = nullptr;
    int n;

    cout << "Vuvedi n: ";
    cin >> n;

    cout << "Vuvedete   " << n << " elementa: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        root = insertBST(root, val);
    }


    inOrder(root);
    cout << endl;

    return 0;
}
