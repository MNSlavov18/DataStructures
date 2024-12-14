#include <iostream>
#include <string>

struct Node {
    std::string data;
    Node* next;
};

void insert(Node*& head, const std::string& value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode; // Ако списъкът е празен
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next; // Обхождаме до края на списъка
        }
        temp->next = newNode;
    }
}

void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

void freeList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    std::string firstName, middleName, lastName;

    std::cout << "Enter your first name: ";
    std::cin >> firstName;
    insert(head, firstName);

    std::cout << "Enter your middle name: ";
    std::cin >> middleName;
    insert(head, middleName);

    std::cout << "Enter your last name: ";
    std::cin >> lastName;
    insert(head, lastName);

    std::cout << "List contents: ";
    printList(head);

    freeList(head);

    return 0;
}