#include <iostream>
using namespace std;

struct Node
{
    int song_ID, duration_sec, duration_min;
    string song_title, artist_name;

    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

void add_song(int song_ID, string song_title, string artist_name, int duration_min, int duration_sec)
{
    struct Node *newNode = new Node();
    newNode->song_ID = song_ID;
    newNode->song_title = song_title;
    newNode->artist_name = artist_name;
    newNode->duration_min = duration_min;
    newNode->duration_sec = duration_sec;

    if (head == NULL)
    {
        head = newNode;
        newNode->next = head;
        tail = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
        tail = newNode;
    }
}

void askDetails(int &song_ID, string &song_title, string &artist_name, int &duration_min, int &duration_sec)
{
    cout << "Enter song ID: ";
    cin >> song_ID;
    cout << "Enter song title: ";
    getline(cin >> ws, song_title);
    cout << "Enter artist name: ";
    getline(cin >> ws, artist_name);
    cout << "Enter duartion in minutes: ";
    cin >> duration_min;
    cout << "Enter duartion in seconds: ";
    cin >> duration_sec;
}

void delete_song(string delete_song_name)
{
    Node *temp = head;
    Node *tempForward;

    if (head->next == head)
    {
        head = NULL;
        return;
    }

    tempForward = head->next;

    if (head->song_title == delete_song_name)
    {
        head = head->next;
        tail->next = head;
        return;
    }

    do
    {
        if (tempForward->song_title == delete_song_name)
        {
            if (tempForward == tail)
            {
                temp->next = head;
                return;
            }
            temp->next = tempForward->next;
            return;
        }

        tempForward = tempForward->next;
        temp = temp->next;
    } while (tempForward->next != head);
}

void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }
    Node *temp = head;
    do
    {
        cout << "Song ID: " << temp->song_ID << endl;
        cout << "Song Title: " << temp->song_title << endl;
        cout << "Artist Name: " << temp->artist_name << endl;
        cout << "Duration: " << temp->duration_min << " min " << temp->duration_sec << " sec " << endl;
        temp = temp->next;

    } while (temp != head);
}

int main(int argc, char const *argv[])
{
    int song_ID, duration_sec, duration_min, choice;
    string song_title, artist_name, delete_song_name;

    while (true)
    {
        cout << "----------Welcome----------" << endl;
        cout << "\n1. Add a song" << endl;
        cout << "2. Remove a song" << endl;
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
            askDetails(song_ID, song_title, artist_name, duration_min, duration_sec);
            add_song(song_ID, song_title, artist_name, duration_min, duration_sec);
            break;
        case 2:
            cout << "Enter the name of song you want to delete: ";
            cin >> delete_song_name;
            delete_song(delete_song_name);
            break;
        case 3:
            display();
            break;

        default:
            cout << "Invalid input!" << endl;
            break;
        }
    }

    return 0;
}
