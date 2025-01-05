#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

// Структура за възел на двоичното дърво
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Функция за построяване на идеално балансирано дърво
TreeNode* buildBalancedTree(const vector<int>& values, int start, int end) {
    if (start > end) {
        return nullptr;
    }

    int mid = start + (end - start) / 2; // Намираме средния елемент
    TreeNode* root = new TreeNode(values[mid]);

    // Рекурсивно строим лявото и дясното поддърво
    root->left = buildBalancedTree(values, start, mid - 1);
    root->right = buildBalancedTree(values, mid + 1, end);

    return root;
}

// Помощна функция за разпечатване на дървото
void printTreeStructure(TreeNode* root, int depth = 0) {
    if (root == nullptr) {
        return;
    }

    // Първо разпечатваме дясното поддърво
    printTreeStructure(root->right, depth + 1);

    // Добавяме отместване за визуализация на структурата
    for (int i = 0; i < depth; ++i) {
        cout << "   ";
    }

    // Печатаме текущия възел
    cout << root->value << endl;

    // След това разпечатваме лявото поддърво
    printTreeStructure(root->left, depth + 1);
}

int main() {
    // l и m са взети от факултетния номер: l = 77, m = 29
    int l = 77;
    int m = 29;

    // Създаваме стойностите за дървото, комбинирайки стойностите от 1 до l и от 1 до m
    vector<int> values;
    for (int i = 1; i <= l; i++) {
        values.push_back(i);
    }
    for (int i = 1; i <= m; i++) {
        values.push_back(l + i); // Избягваме дублиране на стойности
    }

    // Построяване на идеално балансирано дърво
    TreeNode* root = buildBalancedTree(values, 0, values.size() - 1);

    // Разпечатване на дървото като структура
    cout << "Balanced Binary Tree for l = " << l << " and m = " << m << ":\n";
    printTreeStructure(root);

    return 0;
}
