
#include "../../../../Program Files/JetBrains/CLion 2024.1.1/bin/mingw/x86_64-w64-mingw32/include/stddef.h"

#include "iostream";

using namespace std;

struct list
{
    char data;
    list* next;
};

void push(list** head_ref, char new_data)
{
    list* new_node = new list();

    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

char pop(list** head_ref) {
    char l_data=(*head_ref)->data;
    list* temp = (*head_ref)->next;
    delete (*head_ref);
    (*head_ref) = temp;
    
    return l_data;
}

int main()
{    
 list* head = new list;
 head = NULL;

    char input;
    cin>>input;
    while (input != '0') {
        push(&head,input);
        cin>>input;
    }

    while (head != NULL) {
        cout<<pop(&head) << " ";
    }
    cout << endl;

    return 0;
}