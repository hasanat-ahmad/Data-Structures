// Write a C++ program to find the max of an integral data set. The program will ask the user to input the number of data values in the set and each value. The program prints on screen a pointer that points to the max value.


#include <iostream>
using namespace std;

int main() {
   cout << "Enter the length of array: ";
   int length;
   int max = 0;
   cin >> length;
   
   int arr[length];
   cout << "Enter elements: ";
   for (int i = 0; i < length; i++){
       cin >> arr[i];
   }
   
   for(int i = 0; i < length; i++){
       if (arr[i] > max){
           max = arr[i];
       }
   }
   
   int* pointer = &max;
   cout << "Pointer points to max number " << max << " with address as " << pointer;
   
   

    return 0;
}