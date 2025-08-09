#include <iostream>
using namespace std;

int main() {
    
    int arr[10] = {34,3,7,6,8,9};
    
    int number, position;
    cout << "Enter the element you want to insert : ";
    cin >> number;
    cout << "Enter index: ";
    cin >> position;
    
    for(int i = 10; i > position; i --){
        arr[i] = arr[i - 1];
    }
    arr[position] = number;
    cout << endl;

    cout << "The New array is: ";
    
    for(int i = 0; i < 10; i ++){
        cout << arr[i] << " ";
    }
    

    return 0;
}