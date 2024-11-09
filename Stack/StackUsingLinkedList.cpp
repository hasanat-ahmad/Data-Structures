#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *top = NULL;

void createStack(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (top == NULL)
    {
        top = newNode;
        return;
    }
    newNode->next = top;
    top = newNode;
}

void deleteNode()
{
    if (top == NULL)
    {
        cout << "Stack is empty";
    }
    else
    {
        top = top->next;
    }
}

void displayTop()
{
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }
    cout << top->data << endl;
}
void displayStack()
{
    Node *temp = top;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    // createStack(10);
    // createStack(20);
    // createStack(30);
    // deleteNode();
    // displayStack();
    // displayTop();
}