#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void insertAtHead(int data)
{
    struct Node *newNode = new Node();
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

void deleteAtStart()
{
    if (head == NULL)
    {
        cout << "List is empty already" << endl;
    }
    else{
        Node* temp = head;
        head = head->next;
        delete head;
        return;
    }
    
}

void deleteFromTail()
{   
       if (head == NULL && tail ==NULL){
        cout << "List is already empty" << endl;
       }
       else{
        Node* temp = head;
        while (temp->next->next != NULL){
        temp = temp->next;
        
    }
        delete (temp->next);
        temp->next = NULL;
        return;
       }
    
    
}

void insertAt(int position, int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    Node *temp = head;
    while (temp != NULL)
    {
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
void insertAtTail(int data)
{
    struct Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

void print()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{

    int choice;

    while (true)
    {
        cout << "\n";
        cout << "1. Insertion At Head" << endl;
        cout << "2. Insertion At End" << endl;
        cout << "3. Insertion At Specific Point" << endl;
        cout << "4. Display" << endl;
        cout << "5. Delete from beginning" << endl;
        cout << "6. Delete from tail" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1)
        {
            int data;
            cout << "Enter data: ";
            cin >> data;
            cout << "Elements inserted successfully" << endl;
            insertAtHead(data);
        }
        else if (choice == 2)
        {
            insertAtTail(15);
            insertAtTail(16);
            insertAtTail(17);
            cout << "Elements inserted successfully" << endl;
        }
        else if (choice == 3)
        {
            insertAt(10, 11);
            cout << "Elements inserted successfully" << endl;
        }
        else if (choice == 4)
        {
            print();
        }
        else if (choice == 5)
        {
            deleteAtStart();
            cout << "Elements deleted successfully" << endl;
        }
        else if (choice == 6)
        {
            deleteFromTail();
            cout << "Elements deleted successfully" << endl;
        }
        else if (choice == 7)
        {
            cout << "Exiting" << endl;
            break;

        }
    }

    return 0;
}
