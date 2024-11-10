#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *front = NULL;
Node *rear = NULL;

bool isEmpty()
{
    return front == NULL;
}

void enqueue(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (isEmpty())
    {
        front = rear = newNode;
        newNode->next = front; // Pointer to itself making it circular
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
    }
    else
    {
        if (front == rear)
        {
            front = rear = NULL;
        }
        else
        {
            front = front->next;
            rear->next = front;
        }
    }
}

void display()
{
    Node *temp = front;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    }
    while (temp != front);
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    return 0;
}