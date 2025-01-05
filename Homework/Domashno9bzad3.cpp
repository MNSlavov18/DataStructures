#include <iostream>
using namespace std;

// Структура за възел на двоично дърво
struct TreeNode {
    char data;          // Стойност на възела
    TreeNode* left;     // Ляво поддърво
    TreeNode* right;    // Дясно поддърво

    // Конструктор за възел
    TreeNode(char val) : data(val), left(nullptr), right(nullptr) {}
};

// Функция за инфиксно обхождане с отпечатване на скоби
void printInfix(TreeNode* root) {
    if (root == nullptr) return;

    // Ако възелът не е листо, отпечатваме отваряща скоба
    if (root->left || root->right) cout << "(";

    // Рекурсивно обхождаме лявото поддърво
    printInfix(root->left);

    // Печатаме стойността на текущия възел
    cout << root->data;

    // Рекурсивно обхождаме дясното поддърво
    printInfix(root->right);

    // Ако възелът не е листо, отпечатваме затваряща скоба
    if (root->left || root->right) cout << ")";
}

int main() {
    // Създаваме ръчно дървото според условието
    TreeNode* root = new TreeNode('/');           // Корен: /
    root->left = new TreeNode('+');               // Ляво дете: +
    root->right = new TreeNode('-');              // Дясно дете: -

    root->left->left = new TreeNode('a');         // Ляво дете на +: a
    root->left->right = new TreeNode('b');        // Дясно дете на +: b

    root->right->left = new TreeNode('c');        // Ляво дете на -: c
    root->right->right = new TreeNode('d');       // Дясно дете на -: d

    // Извеждаме дървото в инфиксна нотация
    cout << "Infix notation of the tree:\n";
    printInfix(root);
    cout << endl;

    // Освобождаваме заделената памет
    delete root->left->left;
    delete root->left->right;
    delete root->right->left;
    delete root->right->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
