#include <iostream>
using namespace std;

const int stacksize = 100;
int top = -1;
int stackarray[stacksize];

void addToStack(int number)
{
    if (top == stacksize - 1)
    {
        cout << "Array is full";
    }
    else
    {
        top++;
        stackarray[top] = number;
    }
}
void removeFromStack()
{
    if (top == -1)
    {
        cout << "Stack is empty";
    }
    else
    {
        top--;
    }
}

void displayStack()
{
    if (top == -1)
    {
        cout << "Array is Empty";
    }
    else{
        for (int i = 0; i <= top; i++){
            cout << stackarray[i] << endl;
        }
    }
}

int main()
{
    addToStack(14);
    addToStack(15);
    addToStack(16);
    removeFromStack();
    removeFromStack();
    displayStack();
    return 0;
}
