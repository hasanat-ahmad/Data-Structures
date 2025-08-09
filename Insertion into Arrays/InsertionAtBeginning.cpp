#include <iostream>
using namespace std;

int main() {
    
    int arr[10] = {34,3,7,6,8,9};
    
    cout << "The Old array is: ";
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";}
    
    for(int i = 10; i > 0; i --){
        arr[i] = arr[i - 1];
    }

    cout << endl;
    int number;
    cout << "Enter the element you want to insert at the beginning: ";
    cin >> number;
    arr[0] = number;
    cout << "The New array is: ";
    
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";
    }
    

    return 0;
}