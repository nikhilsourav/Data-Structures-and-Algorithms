/*
    Program to demonstrate binary search using recursion.
*/

#include <bits/stdc++.h>
using namespace std;

// Binary search recursive
int binarySearch(int arr[], int size, int element, int low, int high)
{
    // base case
    if (low > high)
        return -1;

    // calculate mid each time
    int mid = (low + high) / 2;

    // logic:
    if (arr[mid] == element)
        return mid;
    else if (arr[mid] > element)
        return binarySearch(arr, size, element, low, mid - 1);
    else
        return binarySearch(arr, size, element, mid + 1, high);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << binarySearch(arr, size, 70, 0, 10);
}