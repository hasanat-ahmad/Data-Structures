#include <iostream>
using namespace std;

struct Node
{
    int quantity;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void createList(int quantity)
{
    Node *newNode = new Node();
    newNode->quantity = quantity;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

int totalEssentialItems()
{
    int total = 0;
    int index = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (index % 2 == 0)
        {
            total += temp->quantity;
        }
        temp = temp->next;
        index++;
    }
    return total;
}

int totalNonEssentialItems()
{
    int total = 0;
    int index = 0;
    Node *current = head;
    while (current != nullptr)
    {
        if (index % 2 != 0)
        {
            total += current->quantity;
        }
        current = current->next;
        index++;
    }
    return total;
}

void SummaryOfEssentialItems()
{
    int essentialTotal = totalEssentialItems();
    Node *newNode = new Node();
    newNode->quantity = essentialTotal;
    newNode->next = head;
    head = newNode;
    if (tail == NULL)
    {
        tail = newNode;
    }
}

void SummaryofnonEssentialItems()
{
    int nonEssentialTotal = totalNonEssentialItems();
    Node *newNode = new Node();
    newNode->quantity = nonEssentialTotal;
    newNode->next = NULL;

    if (tail != NULL)
    {
        tail->next = newNode;
        tail = newNode;
    }
    if (head == NULL)
    {
        head = newNode;
    }
}

void display()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->quantity << " ";
        temp = temp->next;
    }
}

int main()
{
    createList(10);
    createList(20);
    createList(30);
    createList(40);
    createList(50);
    cout << "Total essential items are: " << totalEssentialItems() << endl;
    cout << "Total non-essentail items are: " << totalNonEssentialItems() << endl;
    SummaryOfEssentialItems();
    SummaryofnonEssentialItems();
    display();
    return 0;
}