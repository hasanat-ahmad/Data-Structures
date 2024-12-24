#include <iostream>
using namespace std;

void binarySearch(int arr[], int size, int start, int end, int target)
{
    while (start <= end){
        int mid = (start + end)/2;

        if (target < arr[mid]){
            end = mid - 1;
        }
        else if (target > arr[mid]){
            start = mid + 1;
        }
        else{
            cout << "Target found";
            return;
        }
    }
    cout << "Target not found";
}
int main()
{

    int arr[] = {1, 2, 4, 6, 7, 9};
    int start = 0;
    int size = sizeof(arr)/sizeof(arr[0]);
    int end = sizeof(arr)/sizeof(arr[0]) - 1;

    binarySearch(arr, size, start , end, 10);
    return 0;
}