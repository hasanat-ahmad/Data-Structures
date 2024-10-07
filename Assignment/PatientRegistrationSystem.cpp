#include <iostream>
using namespace std;

struct Node
{
    int registration_no, age;
    string name, address, phone_no;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void createNode(int registration_no, int age, string phone_no, string name, string address)
{
    struct Node *newNode = new Node();
    newNode->registration_no = registration_no;
    newNode->age = age;
    newNode->phone_no = phone_no;
    newNode->name = name;
    newNode->address = address;
    newNode->next = head;
    registration_no++;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
        ;
    }
}

void deleteNode(int number)
{

    Node *temp = head;
    Node *tempForward = temp->next;
    while (temp != NULL)
    {
        if (number == head->registration_no)
        {
            head = head->next;
            delete temp;
        }
        else if (tempForward->registration_no == tail->registration_no)
        {
            temp->next = NULL;
            tail = temp;
            delete tempForward;
        }
        else
        {
            temp->next = tempForward->next;
            delete tempForward;
        }
        tempForward = temp->next;
        temp = temp->next;
    }
}

void askDetails(int &registration_no, int &age, string &phone_no, string &name, string &address)
{
    cout << "Enter registration no.: ";
    cin >> registration_no;
    cout << "Enter the name of the patient: ";
    getline(cin >> ws, name);
    cout << "Enter the age of patient: ";
    cin >> age;
    cout << "Enter address of the patient: ";
    getline(cin >> ws, address);
    cout << "Enter phone no.: ";
    getline(cin >> ws, phone_no);
}

void display()
{
    struct Node *temp = head;
    if (head == NULL)
    {
        cout << "No patients available" << endl;
        return;
    }
    while (temp != NULL)
    {
        cout << "-----------------------------" << endl;
        cout << "Registration no. : " << temp->registration_no << endl;
        cout << "Patient Name: " << temp->name << endl;
        cout << "Patient's Age: " << temp->age << endl;
        cout << "Phone no.: " << temp->phone_no << endl;
        cout << "Patient's Address: " << temp->address << endl;
        cout << "-----------------------------";

        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    int registration_no, age, choice, number;
    string name, address, phone_no;
    Node *next;
    while (true)
    {

        cout << "\n------------Welcome------------" << endl;
        cout << "1. Add a patient" << endl;
        cout << "2. Remove a patient" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
        }

        if (choice == 1)
        {
            askDetails(registration_no, age, phone_no, name, address);
            createNode(registration_no, age, phone_no, name, address);
        }
        else if (choice == 2)
        {
            cout << "Enter registration no. of patient you want to delete: ";
            cin >> number;
            deleteNode(number);
        }
        else if (choice == 3)
        {
            display();
        }
        else if (choice == 4)
        {
            break;
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}
