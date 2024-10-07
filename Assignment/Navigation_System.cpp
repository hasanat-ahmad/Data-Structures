#include <iostream>
using namespace std;

struct Node
{
    string location_name, date, description;
    double longitude_coordinates, latitude_coordiantes;
    Node *next;
    Node *prev;
};

Node *head = NULL;
Node *tail = NULL;

void Add_Location(string location_name, string date, string description, double longitude_coordinates, double latitude_coordinates)
{
    Node *newNode = new Node();
    newNode->location_name = location_name;
    newNode->date = date;
    newNode->description = description;
    newNode->longitude_coordinates = longitude_coordinates;
    newNode->latitude_coordiantes = latitude_coordinates;

    newNode->prev = NULL;
    newNode->next = NULL;

    if (head == NULL && tail == NULL)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void askDetails(string &location_name, string &date, string &description, double &longitude_coordinates, double &latitude_coordinates)
{
    cout << "Enter location name: ";
    getline(cin >> ws, location_name);
    cout << "Enter date: ";
    getline(cin >> ws, date);
    cout << "Location coordinates" << endl;
    cout << "Enter longitude coordinates: ";
    cin >> longitude_coordinates;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    cout << "Enter latitude coordinates: ";
    cin >> latitude_coordinates;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore();
    }
    cout << "Description: ";
    getline(cin >> ws, description);
}

void delete_location(string delete_location_name)
{
    Node *temp = head;
    if (head == NULL)
    {
        cout << "List is empty! Nothing to delete" << endl;
    }
    while (temp != NULL)
    {
        if (temp->location_name == delete_location_name)
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
                temp->prev->next = temp->next;
                temp->next->prev = temp->prev;
            }
            return;
        }

        cout << "Location " << delete_location_name << " not found!" << endl;
        return;

        temp = temp->next;
    }
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Location name: " << temp->location_name << endl;
        cout << "Visited date: " << temp->date << endl;
        cout << "Location coordinates-> " << "Longitude:" << temp->longitude_coordinates << " and Latitude:" << temp->latitude_coordiantes << endl;
        cout << "Description: " << temp->description << endl;
        cout << "--------------------------" << endl;
        cout << endl;
        temp = temp->next;
    }
}

int main()
{
    int choice;
    string location_name, date, description;
    double longitude_coordinates, latitude_coordiantes;
    string delete_location_name;

    while (true)
    {
        cout << "\n---------- Welcome ----------" << endl;
        cout << "1. Add location" << endl;
        cout << "2. Remove location" << endl;
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
            askDetails(location_name, date, description, longitude_coordinates, latitude_coordiantes);
            Add_Location(location_name, date, description, longitude_coordinates, latitude_coordiantes);
            break;
        case 2:
            cout << "Enter the name of the location to delete: ";
            getline(cin >> ws, delete_location_name);
            delete_location(delete_location_name);
            break;
        case 3:
            display();
            break;
        case 4:
            cout << "Exiting program." << endl;
            return 0;
        default:
            cout << "Invalid input! Please try again." << endl;
        }
    }

    return 0;
}
