#include <iostream>
using namespace std;

struct Node
{
    int id, quantity, price;
    string name, description;

    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

int currentID = 1;

void add_item(int id, string name, int quantity, int price, string description)
{
    struct Node *newNode = new Node();
    newNode->id = currentID++;
    newNode->name = name;
    newNode->quantity = quantity;
    newNode->price = price;
    newNode->description = description;

    newNode->next = NULL;
    newNode->prev = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void askDetails(string &name, int &quantity, int &price, string &description)
{

    cout << "Enter the name of item: ";
    getline(cin >> ws, name);
    cout << "Enter the quantity of item: ";
    cin >> quantity;
    cout << "Enter the price of item: ";
    cin >> price;
    cout << "Enter description of item: ";
    getline(cin >> ws, description);
}

void delete_item(string delete_name)
{
    if (head == NULL)
    {
        cout << "List is empty! Nothing to delete" << endl;
        return;
    }
    bool itemFound = false;
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->name == delete_name)
        {
            if (temp == head && temp == tail)
            {
                head = tail = NULL;
            }
            else if (temp == head)
            {
                head = head->next;
                head->prev = NULL;
            }
            else if (temp == tail)
            {
                tail = tail->prev;
                tail->next = NULL;
            }
            else
            {
                temp->next = temp->next->next;
                temp->next->next->prev = temp;
            }
            cout << delete_name << " successfully deleted" << endl;
            itemFound = true;

        }
        temp = temp->next;
    }
    if (!itemFound)
    {
        cout << "No " << delete_name << " found" << endl;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Item ID: " << temp->id << endl;
        cout << "Item Name: " << temp->name << endl;
        cout << "Item Price: " << "Rs. " << temp->price << endl;
        cout << "Item Description: " << temp->description << endl;
        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    int id, quantity, price;
    string name, description, delete_name;
    int choice;
    while (true)
    {
        cout << "----------Welcome----------" << endl;
        cout << "1. Add an item" << endl;
        cout << "2. Remove an item" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }
        switch (choice)
        {
        case 1:
            askDetails(name, quantity, price, description);
            add_item(id, name, quantity, price, description);
            break;
        case 2:
            cout << "Enter the name of item you want to delete: ";
            cin >> delete_name;
            delete_item(delete_name);
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;

        default:
            cout << "Invalid input! Try again" << endl;
            ;
        }
    }

    return 0;
}
