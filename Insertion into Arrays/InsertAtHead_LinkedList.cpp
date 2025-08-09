#include <iostream>
using namespace std;

// Class definition for a Node in the linked list
class Node {
    public:
    int data;      // Data part of the node
    Node* next;    // Pointer to the next node in the list
    
    // Constructor to initialize a node with given data
    Node(int data) {
        this -> data = data; // Assign the provided data to the node's data
        this -> next = NULL; // Initially, the next pointer is set to NULL
    }
};

// Function to insert a new node at the head of the list
void insertAtHead(Node* &head, int d) {
    Node* temp = new Node(d); // Create a new node with the given data
    temp -> next = head;      // Set the new node's next to point to the current head
    head = temp;              // Update the head to be the new node
}

// Function to print the linked list starting from the head
void print(Node* &head) {
    Node* ptr = head;         // Start with the head node
    while (ptr != NULL) {     // Traverse the list until the end (NULL)
        cout << ptr -> data << " "; // Print the data of the current node
        ptr = ptr -> next;    // Move to the next node
    }
    cout << endl;             // Print a newline after printing the list
}

int main() {
    Node* node1 = new Node(10); // Create the first node with data 10
    Node* head = node1;         // Initialize the head of the list to the first node
    print(head);                // Print the list (should print "10")
    
    insertAtHead(head, 12);     // Insert a new node with data 12 at the head
    print(head);                // Print the updated list (should print "12 10")

    return 0;                   // End of the program
}
