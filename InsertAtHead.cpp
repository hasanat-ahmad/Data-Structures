#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertAtHead(int data){
    struct Node* newNode = new Node();
    newNode->data = data;
    newNode->next = head;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void print() {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << endl;
        temp = temp->next;
    }
} 

int main(int argc, char const *argv[])
{
    insertAtHead(10);
    insertAtHead(11);
    insertAtHead(12);
    insertAtHead(13);
    insertAtHead(14);

    print();

    return 0;
}
