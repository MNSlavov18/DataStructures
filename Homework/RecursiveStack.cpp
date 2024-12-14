#include <iostream>
#include <string>

struct Node {
    char data;
    Node* next;
};

void push(Node*& top, char value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

void printReverse(Node* node) {
    if (node == nullptr) {
        return;
    }
    printReverse(node->next);
    std::cout << node->data << " ";
}

void freeStack(Node*& top) {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}

int main() {
    Node* stackTop = nullptr;
    std::string name;

    std::cout << "Add your name: ";
    std::cin >> name;

    for (char ch : name) {
        push(stackTop, ch);
    }

    std::cout << "Name: ";
    printReverse(stackTop);
    std::cout << std::endl;

    freeStack(stackTop);

    return 0;
}