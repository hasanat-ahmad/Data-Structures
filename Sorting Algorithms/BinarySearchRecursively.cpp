#include <iostream>
using namespace std;

void binarySearch(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        cout << "Target not found" << endl;
        return;
    }

    int mid = start + (end - start) / 2; // Prevent integer overflow

    if (target < arr[mid])
    {
        binarySearch(arr, start, mid - 1, target); // Search in the left half
    }
    else if (target > arr[mid])
    {
        binarySearch(arr, mid + 1, end, target); // Search in the right half
    }
    else
    {
        cout << "Target found at index: " << mid << endl;
    }
}

int main()
{
    int arr[] = {1, 2, 4, 6, 7, 9, 11};
    int start = 0;
    int end = sizeof(arr) / sizeof(arr[0]) - 1;

    binarySearch(arr, start, end, 9);  // Target found
    binarySearch(arr, start, end, 10); // Target not found
    return 0;
}
