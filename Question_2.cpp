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

void deleteNode(int number, int registration_no)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (number == head->registration_no)
        {
            head = head->next;
            delete temp;
        }
        else if (registration_no == number)
        {
            delete temp;
        }
        temp = temp->next;
    }
}

void askDetails(int &age, string &phone_no, string &name, string &address)
{
    cout << "Enter the name of the patient: "<< endl;
    getline(cin >> ws, name);
    cout << "Enter the age of patient: "<< endl;
    cin >> age;
    cout << "Enter address of the patient: " << endl;
    getline(cin, address);
    cout << "Enter phone no.: " << endl;
    getline(cin, phone_no);
    createNode(registration_no, age, phone_no, name, address);
}

void display()
{
    if (head == NULL)
    {
        cout << "No patients available" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << "-----------------------------" << endl;
        cout << "Patient Name: " << temp->name << endl;
        cout << "Patient's Age: " << temp->age << endl;
        cout << "Patient's Address: " << temp->address << endl;
        cout << "Registration no. : " << temp->registration_no << endl;
        cout << "Phone no.: " << temp->phone_no << endl;
        cout << "-----------------------------";

        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    while (true)
    {
        int registration_no = 1;
        int number, choice;
        cout << "\n------------Welcome------------" << endl;
        cout << "1. Add a patient" << endl;
        cout << "2. Remove a patient" << endl;
        cout << "3. Display" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int age;
            string phone_no;
            string name;
            string address;
            // askDetails(age, phone_no, name, address);

            
        }
        else if (choice == 2)
        {
            cout << "Enter registration no. of patient you want to delete: ";
            cin >> number;
            deleteNode(number, registration_no);
        }
        else if (choice == 3)
        {
            display();
        }
        else
        {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}
