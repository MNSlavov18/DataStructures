#include <iostream>
#include <string>
#include <vector>
#include <iomanip>  // За setw()
using namespace std;

// Структура за възел от двоично дърво за търсене
struct Node {
    int value;
    Node* left;
    Node* right;
    Node(int v) : value(v), left(nullptr), right(nullptr) {}
};

// Функция за вмъкване в BST (без повторения).
// Ако елементът вече съществува, не го вмъкваме повторно.
Node* insertBST(Node* root, int val) {
    if (!root) {
        // Ако дървото (поддървото) е празно, създаваме нов възел
        return new Node(val);
    }
    if (val < root->value) {
        root->left = insertBST(root->left, val);
    }
    else if (val > root->value) {
        root->right = insertBST(root->right, val);
    }
    // Ако val == root->value, нищо не правим (пропускаме дубликат)
    return root;
}

// Рекурсивна функция за отпечатване на дървото "настрани":
// - Първо печата дясното поддърво (с по-големи отмествания);
// - После печата корена;
// - После лявото поддърво.
void printTree(Node* root, int space = 0) {
    if (!root) return;
    // Стъпка на отместване (колко места да се изместим надясно)
    const int INDENT = 5;

    space += INDENT;

    // Първо десен наследник
    printTree(root->right, space);

    // Печатаме текущия възел
    cout << setw(space) << root->value << "\n";

    // После ляв наследник
    printTree(root->left, space);
}

// Инфиксно (in-order) обходяне на BST
void inorderTraversal(Node* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->value << " ";
    inorderTraversal(root->right);
}

int main() {
    // Факултетен номер и ЕГН (първите 4 цифри) - твърдо зададени според условието
    string facultyNumber = "11279";
    string egnPart       = "0449";

    // 1) Разбиваме факултетния номер на единични цифри
    //    Пример: "11279" => 1,1,2,7,9
    vector<int> valuesToInsert;

    // A) Единични цифри от факултетния номер
    for (char c : facultyNumber) {
        // Превръщаме символ -> цяло число
        valuesToInsert.push_back(c - '0');
    }

    // B) Единични цифри от първите 4 цифри на ЕГН
    for (char c : egnPart) {
        valuesToInsert.push_back(c - '0');
    }

    // 2) Разбиваме на двуцифрени групи факултетния номер
    //    Пример: "11279" => "11", "27", "9" (остатък)
    //    Ще парснем всяка групичка като цяло число
    for (size_t i = 0; i < facultyNumber.size(); i += 2) {
        if (i + 1 < facultyNumber.size()) {
            // Имаме 2 символа
            int twoDigit = stoi(facultyNumber.substr(i, 2));
            valuesToInsert.push_back(twoDigit);
        } else {
            // Остатък от 1 цифра
            int oneDigit = facultyNumber[i] - '0';
            valuesToInsert.push_back(oneDigit);
        }
    }

    // 3) Двуцифрени групи от EГН: "04" -> 4, "49" -> 49 и т.н.
    for (size_t i = 0; i < egnPart.size(); i += 2) {
        if (i + 1 < egnPart.size()) {
            int twoDigit = stoi(egnPart.substr(i, 2));
            valuesToInsert.push_back(twoDigit);
        } else {
            // Ако случайно има остатък от 1 цифра
            int oneDigit = egnPart[i] - '0';
            valuesToInsert.push_back(oneDigit);
        }
    }

    // Създаваме празно дърво (указател към корена)
    Node* root = nullptr;

    // Вмъкваме стойностите в BST (пропускаме дубликати)
    for (int val : valuesToInsert) {
        root = insertBST(root, val);
    }

    // 4) Отпечатваме как изглежда дървото (грубо, настрани)
    cout << "========== BST STRUCTURE ==========\n";
    printTree(root, 0);

    // 5) Инфиксно обходяне (ляво-корен-дясно)
    cout << "\n========== IN-ORDER TRAVERSAL ==========\n";
    inorderTraversal(root);
    cout << endl;

    // Освобождаване на динамичната памет (по желание)
    // (за учебна цел често се пропуска, но в реални приложения е важно)
    // Тук може да се добави рекурсивна функция за триене на дървото

    return 0;
}