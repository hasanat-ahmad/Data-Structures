#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node* top = NULL;

void push(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = top;             
    top = newNode;                   
}

void pop() {
    if (top == NULL) {
        cout << "Stack Underflow" << endl;
    } else {
        cout << "The popped element is " << top->data << endl;
        Node* temp = top; 
        top = top->next;
        delete temp;    
    }
}

bool isPrime(int num) {
    if (num <= 1) return false; 
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false; 
    }
    return true; 
}

void display() {
    Node* temp = top;
    if (top == NULL) {
        cout << "Stack is empty" << endl;
    } else {
        cout << "Stack elements are: " << endl;
        while (temp != NULL) {
            if (temp->data % 2 == 0) {
                cout << "Even data: " << temp->data << endl;
            } else if (isPrime(temp->data)) {
                cout << "Prime data: " << temp->data << endl;
            } else {
                cout << "Odd data: " << temp->data << endl;
            }
            temp = temp->next; 
        }
    }
    cout << endl;
}

int main() {
  
    push(3);
    push(4);
    push(5);
    push(6);
    display(); 

    pop();    
    display(); 

    return 0;
}