#include <iostream>
#include <string>
using namespace std;

// Структура на възел от двоичното дърво
struct Node {
    string value; // Оператор или операнд
    Node* left;   // Ляво поддърво
    Node* right;  // Дясно поддърво

    Node(string val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция за постфиксно обхождане
void postOrderTraversal(Node* root, int& step) {
    if (root != nullptr) {
        // Рекурсивно обхождане на лявото поддърво
        postOrderTraversal(root->left, step);

        // Рекурсивно обхождане на дясното поддърво
        postOrderTraversal(root->right, step);

        // Посещаване на текущия възел
        cout << "Step " << ++step << ": " << root->value << endl;
    }
}

int main() {
    // Създаване на дървото за израза (a / b + c) * ((d + e) - 3 * h)

    // Ляво поддърво (a / b + c)
    Node* a = new Node("a");
    Node* b = new Node("b");
    Node* divide = new Node("/");
    divide->left = a;
    divide->right = b;

    Node* c = new Node("c");
    Node* plus1 = new Node("+");
    plus1->left = divide;
    plus1->right = c;

    // Дясно поддърво ((d + e) - 3 * h)
    Node* d = new Node("d");
    Node* e = new Node("e");
    Node* plus2 = new Node("+");
    plus2->left = d;
    plus2->right = e;

    Node* three = new Node("3");
    Node* h = new Node("h");
    Node* multiply = new Node("*");
    multiply->left = three;
    multiply->right = h;

    Node* minus = new Node("-");
    minus->left = plus2;
    minus->right = multiply;

    // Коренът на дървото (*)
    Node* root = new Node("*");
    root->left = plus1;
    root->right = minus;

    // Постфиксно обхождане
    cout << "Postfix traversal steps:" << endl;
    int step = 0;
    postOrderTraversal(root, step);

    return 0;
}
