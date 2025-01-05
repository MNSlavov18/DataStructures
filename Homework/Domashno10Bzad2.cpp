#include <iostream>
#include <string>
#include <vector>
#include <queue>    // За BFS (std::queue)
#include <iomanip>  // За setw()
using namespace std;

// ===================================================
// Структура на възел от двоично дърво за търсене (BST)
// ===================================================
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// ==================================
// Функция за вмъкване в BST (без дубликати)
// ==================================
Node* insertBST(Node* root, int val) {
    if (!root) {
        return new Node(val);
    }
    if (val < root->value) {
        root->left = insertBST(root->left, val);
    } else if (val > root->value) {
        root->right = insertBST(root->right, val);
    }
    // Ако val == root->value, не вмъкваме втори път
    return root;
}

// ==================================
// Печатане на BST „настрани“ (debug visualization)
// ==================================
void printTree(Node* root, int space = 0) {
    if (!root) return;
    const int INDENT = 5;
    space += INDENT;

    // Първо десният клон
    printTree(root->right, space);

    // Печатаме текущия възел
    cout << setw(space) << root->value << "\n";

    // После левият клон
    printTree(root->left, space);
}

// ==================================
// Инфиксно (in-order) обходяне
// (ляво-корен-дясно)
// ==================================
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

// ==================================
// Намиране височина (дълбочина) на BST
// ==================================
int findHeight(Node* root) {
    if (!root) return 0;
    int leftH = findHeight(root->left);
    int rightH = findHeight(root->right);
    return 1 + max(leftH, rightH);
}

// ==================================
// Броене на листата в BST
// (листо = възел без деца)
// ==================================
int countLeaves(Node* root) {
    if (!root) return 0;
    if (!root->left && !root->right) {
        // Няма ляво, няма дясно дете => листо
        return 1;
    }
    // Броим листата вляво и вдясно
    return countLeaves(root->left) + countLeaves(root->right);
}

// ==================================
// Обход в ширина (BFS) и отпечатване по нива
// ==================================
void bfsTraversal(Node* root) {
    if (!root) return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->value << " ";

        // Добавяме децата, ако ги има
        if (current->left)  q.push(current->left);
        if (current->right) q.push(current->right);
    }
}

// ==================================
// Главна функция
// ==================================
int main() {
    // Същите данни като в Task 1
    string facultyNumber = "11279";
    string egnPart       = "0449";

    // ----- Събираме всички стойности, които ще вмъкнем в BST -----
    vector<int> valuesToInsert;

    // (A) Единични цифри от факултетния номер
    for (char c : facultyNumber) {
        valuesToInsert.push_back(c - '0');
    }

    // (B) Единични цифри от първите 4 цифри на ЕГН
    for (char c : egnPart) {
        valuesToInsert.push_back(c - '0');
    }

    // (C) Двуцифрени групи от фак. номер (11279 -> 11, 27, 9)
    for (size_t i = 0; i < facultyNumber.size(); i += 2) {
        if (i + 1 < facultyNumber.size()) {
            int twoDigit = stoi(facultyNumber.substr(i, 2));
            valuesToInsert.push_back(twoDigit);
        } else {
            // Остатък
            int oneDigit = facultyNumber[i] - '0';
            valuesToInsert.push_back(oneDigit);
        }
    }

    // (D) Двуцифрени групи от EГН (0449 -> 04=>4, 49=>49)
    for (size_t i = 0; i < egnPart.size(); i += 2) {
        if (i + 1 < egnPart.size()) {
            int twoDigit = stoi(egnPart.substr(i, 2));
            valuesToInsert.push_back(twoDigit);
        } else {
            // Остатък
            int oneDigit = egnPart[i] - '0';
            valuesToInsert.push_back(oneDigit);
        }
    }

    // ----- Създаваме BST, като вмъкваме последователно (без дубликати) -----
    Node* root = nullptr;
    for (int val : valuesToInsert) {
        root = insertBST(root, val);
    }

    // ----------------------------------------------------------
    // Част 1: Печатаме как изглежда дървото (за проверка)
    // ----------------------------------------------------------
    cout << "============== BST STRUCTURE (debug) ==============\n";
    printTree(root);

    // ----------------------------------------------------------
    // Част 2: Инфиксно обходяне (както в Task 1)
    // ----------------------------------------------------------
    cout << "\n============== IN-ORDER TRAVERSAL ==============\n";
    inorderTraversal(root);
    cout << endl;

    // ----------------------------------------------------------
    // (Task 2) Допълнителни операции
    // ----------------------------------------------------------

    // 1) Височина (дълбочина) на дървото
    cout << "\nHeight of BST = " << findHeight(root) << endl;

    // 2) Броене на листата (nodes with no children)
    cout << "Number of leaves = " << countLeaves(root) << endl;

    // 3) BFS обход (в ширина) – печат по нива
    cout << "BFS (level-order) traversal = ";
    bfsTraversal(root);
    cout << endl;

    return 0;
}