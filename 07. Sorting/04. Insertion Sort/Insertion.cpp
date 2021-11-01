/*
    * O(n^2) algorithm
    * O(n) in Best Case
    * Stable and In place
    * Used for small arrays (TimSort and IntraSort)
*/

#include <bits/stdc++.h>
using namespace std;

// Insertion Sort
void insertionSort(int *arr, int size)
{
    // logic:
    for (int i = 1; i < size; i++)
    {
        // current element is key
        int key = arr[i];

        // make room to insert the key
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }

        // insert key in correct position
        arr[j + 1] = key;
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {20, 5, 40, 60, 10, 30};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    insertionSort(arr, size);

    // output
    for (auto x : arr)
        cout << x << " ";
}