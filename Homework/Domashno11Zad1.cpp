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

// ----------------------------------------------------------
// ОТТУК НАДОЛУ: Добавяме функционалност за ИЗТРИВАНЕ от BST
// ----------------------------------------------------------

// Намира възел с минимална стойност (лявото надясно)
Node* findMin(Node* root) {
    if (!root) return nullptr;
    while (root->left) {
        root = root->left;
    }
    return root;
}

// Функция за изтриване на възел със стойност val от BST
Node* deleteNode(Node* root, int val) {
    if (!root) {
        return nullptr;  // Празно дърво
    }

    if (val < root->value) {
        root->left = deleteNode(root->left, val);
    }
    else if (val > root->value) {
        root->right = deleteNode(root->right, val);
    }
    else {
        // Намерихме възела за изтриване:

        // 1) Няма деца (листо) или има само едно дете
        if (!root->left) {
            Node* tmp = root->right;
            delete root;
            return tmp;
        } else if (!root->right) {
            Node* tmp = root->left;
            delete root;
            return tmp;
        }

        // 2) Има две деца:
        // Търсим най-малкия елемент в дясното поддърво
        Node* minRightSubtree = findMin(root->right);
        // Копираме стойността му в текущия възел
        root->value = minRightSubtree->value;
        // Изтриваме онзи възел (в дясното поддърво),
        // който вече "преместихме" тук
        root->right = deleteNode(root->right, minRightSubtree->value);
    }

    return root;
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
    cout << "============== BST STRUCTURE (initial) ==============\n";
    printTree(root);

    // ----------------------------------------------------------
    // Част 2: Инфиксно обходяне
    // ----------------------------------------------------------
    cout << "\n============== IN-ORDER TRAVERSAL ==============\n";
    inorderTraversal(root);
    cout << endl;

    // ----------------------------------------------------------
    // Допълнителни операции (височина, брой листа, BFS)
    // ----------------------------------------------------------
    cout << "\nHeight of BST = " << findHeight(root) << endl;
    cout << "Number of leaves = " << countLeaves(root) << endl;
    cout << "BFS (level-order) traversal = ";
    bfsTraversal(root);
    cout << endl << endl;

    // ----------------------------------------------------------
    // НОВО: Изтриване на възли по зададени стойности
    // ----------------------------------------------------------
    cout << "Колко стойности желаете да изтриете? ";
    int k;
    cin >> k;

    for(int i = 0; i < k; i++) {
        cout << "Въведете стойност за изтриване: ";
        int delValue;
        cin >> delValue;

        // Изтриваме от дървото (ако стойността я има)
        root = deleteNode(root, delValue);

        // Печатаме резултата
        cout << "\n--- Дървото след изтриване на " << delValue << " ---\n";
        printTree(root);
        cout << "\nIn-order след изтриване: ";
        inorderTraversal(root);
        cout << "\n\n";
    }

    return 0;
}

функция изтрийВъзел(root, key):
    // 1. Намираме възела за триене, като търсим (key) в ДДП
    current = root
    parent = NULL

    докато current != NULL и current->стойност != key:
        parent = current
        ако key < current->стойност:
            current = current->left
        иначе:
            current = current->right

    // Ако не сме намерили key, няма какво да трием
    ако current == NULL:
        връщаме root   // или нищо не правим

    // 2. Разглеждаме трите случая

    // Случай А: current е лист (няма деца)
    ако current->left == NULL и current->right == NULL:
        ако parent == NULL:
            // Трием корена, който е и единственият възел
            root = NULL
        иначе ако parent->left == current:
            parent->left = NULL
        иначе:
            parent->right = NULL

        // освобождаваме current, ако е нужно
        върни root

    // Случай Б: current има само едно дете
    ако current->left == NULL и current->right != NULL:
        // има само дясно дете
        ако parent == NULL:
            // Ако трием корена
            root = current->right
        иначе ако parent->left == current:
            parent->left = current->right
        иначе:
            parent->right = current->right

        // освобождаваме current
        върни root
    иначе ако current->left != NULL и current->right == NULL:
        // има само ляво дете
        ако parent == NULL:
            // Ако трием корена
            root = current->left
        иначе ако parent->left == current:
            parent->left = current->left
        иначе:
            parent->right = current->left

        // освобождаваме current
        върни root

    // Случай В: current има две деца
    иначе:
        // Търсим in-order наследника (най-левия възел в дясното поддърво)
        successor = current->right
        successorParent = current

        докато successor->left != NULL:
            successorParent = successor
            successor = successor->left

        // Копираме стойността на successor в current
        current->стойност = successor->стойност

        // Сега трябва да изтрием стария successor
        // Той със сигурност има 0 или 1 дете (защото е най-левият)
        ако successor->right != NULL:
            // successor има дясно дете
            ако successorParent->left == successor:
                successorParent->left = successor->right
            иначе:
                successorParent->right = successor->right
        иначе:
            // successor е лист
            ако successorParent->left == successor:
                successorParent->left = NULL
            иначе:
                successorParent->right = NULL

        // освобождаваме successor
        върни root
