#include <iostream>
using namespace std;

struct Visitor
{
    int visitor_ID, ride_count;
    string visitor_name, ticket_type;

    Visitor *next;
};

Visitor *head = NULL;
Visitor *tail = NULL;


void add_visitor(int visitor_ID, string visitor_name, string ticket_type, int ride_count)
{
    Visitor *newVisitor = new Visitor();
    newVisitor->visitor_ID = visitor_ID;
    newVisitor->visitor_name = visitor_name;
    newVisitor->ticket_type = ticket_type;
    newVisitor->ride_count = ride_count;

    if (head == NULL)
    {
        head = newVisitor;
        newVisitor->next = head;
        tail = newVisitor;
    }
    else
    {
        tail->next = newVisitor;
        newVisitor->next = head;
        tail = newVisitor;
    }
}


void remove_front_visitor()
{
    if (head == NULL)
    {
        cout << "Queue is empty. No visitors to remove." << endl;
        return;
    }

    if (head == tail)
    {
        
        delete head;
        head = NULL;
        tail = NULL;
    }
    else
    {
        Visitor *temp = head;
        head = head->next;
        tail->next = head;
        delete temp;
    }

    cout << "Visitor at the front has been removed after completing their turn." << endl;
}


void move_front_to_back()
{
    if (head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    
    if (head == tail)
    {
        cout << "Only one visitor in the queue. No need to move." << endl;
        return;
    }

    
    tail = head;
    head = head->next;
    tail->next = head;

    cout << "Moved front visitor to the back of the queue." << endl;
}


void display()
{
    if (head == NULL)
    {
        cout << "Queue is empty." << endl;
        return;
    }

    Visitor *temp = head;
    do
    {
        cout << "Visitor ID: " << temp->visitor_ID << endl;
        cout << "Visitor Name: " << temp->visitor_name << endl;
        cout << "Ticket Type: " << temp->ticket_type << endl;
        cout << "Ride Count: " << temp->ride_count << endl;
        temp = temp->next;
    } while (temp != head);
}

int main()
{
    int visitor_ID, ride_count, choice;
    string visitor_name, ticket_type;

    while (true)
    {
        cout << "\n---------- Theme Park Ride Queue System ----------" << endl;
        cout << "1. Add a visitor to the queue" << endl;
        cout << "2. Remove the front visitor" << endl;
        cout << "3. Move the front visitor to the back of the queue" << endl;
        cout << "4. Display queue" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter Visitor ID: ";
            cin >> visitor_ID;
            cout << "Enter Visitor Name: ";
            cin.ignore();
            getline(cin, visitor_name);
            cout << "Enter Ticket Type (VIP/General): ";
            getline(cin, ticket_type);
            cout << "Enter Ride Count: ";
            cin >> ride_count;
            add_visitor(visitor_ID, visitor_name, ticket_type, ride_count);
            break;

        case 2:
            remove_front_visitor();
            break;

        case 3:
            move_front_to_back();
            break;

        case 4:
            display();
            break;

        case 5:
            return 0;

        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }

    return 0;
}
