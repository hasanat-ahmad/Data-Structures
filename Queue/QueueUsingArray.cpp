#include <iostream>
using namespace std;

const int queuesize = 10;
int arr[queuesize];
int front = -1;
int back = -1;

void enqueue(int d){
    if (queuesize == back + 1){
        cout << "Queue is full!";
    }
    else{
        if (front == -1 && back == -1){
            front++;
            back++;
            arr[back] = d;
        }
        else{
            back++;
            arr[back] = d;
        }
    }
}

void dequeue(){
    if (front == -1 && back == -1 || front > back){
        cout << "Queue is empty!";
    }
    else{
        front++;
    }
}

void display(){
    if (front == -1 && back == -1 || front > back){
        cout << "Queue is empty!";
    }
    else{
        for (int i = front; i <= back; i++){
            cout << arr[i] << " ";
        }
    }
}

void displayfront(){
    if (front == -1 && back == -1){
        cout << "Queue is empty!";
    }
    else{
        cout << arr[front];
    }
}

bool isEmpty(){
    if (front == -1 && back == -1 || front > back){
        cout << "Queue is empty!";
        return true;
    }
    else return false;
}

int main(){
    enqueue(5);
    enqueue(6);
    enqueue(7);
    enqueue(8);
    dequeue();
    display();
    displayfront();
    isEmpty();
}