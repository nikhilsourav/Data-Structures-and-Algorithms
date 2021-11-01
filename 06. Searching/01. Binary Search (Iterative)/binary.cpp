/*
    Program to demonstrate binary search using iteration.
*/

#include <bits/stdc++.h>
using namespace std;

// Binary search iterative
int binarySearch(int arr[], int size, int element)
{
    // init low and high
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        // initialize mid
        int mid = (low + high) / 2;

        // base case
        if (arr[mid] == element)
            return mid;

        // element greater than mid
        else if (arr[mid] < element)
            low = mid + 1;

        // element smaller than mid
        else
            high = mid - 1;
    }

    // if not found
    return -1;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    /* ============= Binary search in array (return index) =============== */
    cout << "Binary search in array:" << binarySearch(arr, size, 80) << "\n";

    /* ============= Binary search in vectors (return true or false) =============== */
    vector<int> vrr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Binary search in vector: " << binary_search(vrr.begin(), vrr.end(), 9) << "\n";
}