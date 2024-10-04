#include <iostream>
using namespace std;

struct Student{
    string name;
    string address;
    int age;
    double GPA;

    Student * next;
};

Student* head = NULL;
Student* tail = NULL;

void createNode(string name, string address, int age, double GPA){
    Student* std = new Student();

    std->name = name;
    std->address = address;
    std->age = age;
    std->GPA = GPA;

    if (head == NULL && tail ==NULL){
        head = std;
        tail = std;
    }
    else{
        std->next = head;
        head = std;
    }
}

void display()
{
    Student* temp = head;

    while (temp != NULL)
    {
        cout << temp->name << " ";
        cout << temp->address << " ";
        cout << temp->age << " ";
        cout << temp->GPA << " ";

        temp = temp->next;
    }
    
    
}

void highestGPA()
{
    Student* temp = head;
    Student* highestGPA = head;

    while (temp != NULL){
        if (temp->GPA > highestGPA->GPA){
            highestGPA = temp;
        }
        temp = temp->next;
    }
    cout << "Student with the highest GPA:" << endl;
    cout << "Name: " << highestGPA->name << endl;
    cout << "Address: " << highestGPA->address << endl;
    cout << "Age: " << highestGPA->age << endl;
    cout << "GPA: " << highestGPA->GPA << endl;
}


int main(){
    createNode("Hasanat", "Kaddi", 20, 3.86);
    createNode("Arsalan", "Dagai", 25, 2.86);
    createNode("Mustafa", "KSK", 22, 2.2);
    
    highestGPA();
}