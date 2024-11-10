#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* front = NULL;
Node* back = NULL;

void enqueue(int data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;

    if (front == NULL && back == NULL){
        front = newNode;
        back = newNode;
    }
    else{
        back->next = newNode;
        back = newNode;
    }
}

void dequeue(){
    if (front == NULL){
        cout << "Queue is empty!";
        return;
    }
    front = front->next;
}

void displayFront(){
    if (front == NULL){
        cout << "Queue is empty!";
        return;
    }
    cout << front->data;
}
    
void display(){
    Node* temp = front;
    while (temp != NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main(){
    enqueue(20);
    enqueue(10);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
    displayFront();
}