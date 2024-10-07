#include <iostream>
using namespace std;

struct Node
{
    string task_name;
    string task_description;
    string priority;
    int deadline;
    Node *next;
};

struct Node *head = NULL;
Node *tail = NULL;

void ask(string &task_name, string &task_description, string &priority, int &deadline)
{

    cout << "Enter task name: ";
    cin >> task_name;
    cin.ignore();
    cout << "Enter task description: ";
    getline(cin, task_description);
    cout << "Enter the priority (High/Medium/Low): ";
    cin >> priority;
    cout << "Enter deadline: ";
    cin >> deadline;
    cout << "Task successfully added";
}

void createNode(string task_name, string task_description, string priority, int deadline)
{
    struct Node *newNode = new Node();
    newNode->task_name = task_name;
    newNode->task_description = task_description;
    newNode->priority = priority;
    newNode->deadline = deadline;
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
void deleteNode(string task_name)
{
    string delete_task_name;
    cout << "Enter the task name you want to delete: ";
    cin >> delete_task_name;
    if (head == NULL)
    {
        cout << "List is empty" << endl;
    }
    else if (head->task_name == task_name)
    {
        struct Node *temp = head;
        head = head->next;
        delete temp;
        cout << "Successfully deleted";
    }
    else
    {
        cout << "There is no such task as " << delete_task_name;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "No task available" << endl;
        return;
    }
    struct Node *temp = head;
    while (temp != NULL)
    {
        cout << "-----------------------------" << endl;
        cout << "Task Name: " << temp->task_name << endl;
        cout << "Task Description: " << temp->task_description << endl;
        cout << "Priority: " << temp->priority << endl;
        cout << "Deadline: " << temp->deadline << endl;
        cout << "-----------------------------";

        temp = temp->next;
    }
}

int main(int argc, char const *argv[])
{
    string task_name;
    string task_description;
    string priority;
    int deadline, choice;

    while (true)
    {
        cout << "\n -------------------WELCOME------------------" << endl;
        cout << "1. Add a task" << endl;
        cout << "2. Remove a task" << endl;
        cout << "3. Display to-do list" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Do not enter a character! Please enter a number between 1-4" << endl;
            continue;
        }
        switch (choice)
        {
        case 1:
            ask(task_name, task_description, priority, deadline);
            createNode(task_name, task_description, priority, deadline);
            break;
        case 2:
            deleteNode(task_name);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting";
            return 0;
        default:
            cout << "Invalid choice! Try again";
            break;
        }
    }

    return 0;
}
