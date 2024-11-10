#include <iostream>
using namespace std;

const int queueSize = 100;
int arr[queueSize];
int front = -1, rear = -1;

bool isFull()
{
    return ((rear + 1) % queueSize == front);
}

bool isEmpty()
{
    return front == -1;
}

void enqueue(int d)
{
    if (isFull())
    {
        cout << "Overflow";
    }
    else
    {
        if (front == -1 && rear == -1)
        {
            front++;
            rear++;
            arr[rear] = d;
            return;
        }
        rear = (rear + 1) % queueSize;
        arr[rear] = d;
    }
}

void dequeue()
{
    if (isEmpty())
    {
        cout << "Queue is empty";
    }
    else if (rear == front)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % queueSize;
    }
}

void display()
{
    int i = front;
    while (i != rear)
    {
        cout << arr[i] << " ";
        i = (i + 1) % queueSize; // Circular increment
    }
    cout << arr[rear] << endl; // Display the last element
}

int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    dequeue();
    display();
}