#include <iostream>
#include <string>
using namespace std;

struct Student{
    string name;
    string address;
    int age;
    double gpa;
    Student* next;

};

Student* head = NULL;
Student* tail = NULL;

void createNode(string name, string address, int age, double gpa ){
    struct Student* newNode = new Student();
    newNode->name = name;
    newNode->address = address;
    newNode->age = age;
    newNode->gpa = gpa;
    newNode->next = NULL;

    if (head == NULL && tail == NULL){
        head = newNode;
        tail = newNode;
    }
    else{
        newNode->next = head;
        head = newNode;
    }

}
void display(){
    Student* temp = head;
    while (temp != NULL){
        cout << temp->name << endl;
        cout << temp->gpa << endl;
        cout << temp->address << endl;
        cout << temp->age << endl;

        temp = temp->next;
    }
}
void ask(string name, string address, int age, double gpa){
    cin >> name;
    cin >> address;
    cin >> age;
    cin >> gpa;
}

int main()
{   
    string name,address; 
    int age;
    double gpa;
    Student* next;


    createNode(name, address, age, gpa);
    ask(name, address,age, gpa);
    display();
}