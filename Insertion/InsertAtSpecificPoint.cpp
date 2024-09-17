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

void insertAt(int position, int data) {
    struct Node* newNode = new Node();
    newNode->data = data;
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == position)
        {
            
            newNode->next = temp->next;
            temp->next = newNode;

            if (temp == tail)
            {
                tail = newNode;
            }
            
            return;
        }
        temp = temp->next;
    }
} 

int main(int argc, char const *argv[])
{
    insertAtHead(10);
    insertAtHead(12);
    insertAtHead(13);
    insertAtHead(14);
    insertAtHead(15);
    insertAt(12,11);

    print();

    return 0;
}
