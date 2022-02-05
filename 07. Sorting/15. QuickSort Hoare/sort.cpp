/*
    * Worst case O(n^2)
    * Unstable
*/

#include <bits/stdc++.h>
using namespace std;

// Quicksort using hoare partition
int hoarePartition(int arr[], int low, int high)
{
    // init vars
    int pivot = arr[low]; // assuming pivot is first element
    int i = low - 1, j = high + 1;

    // logic:
    while (1)
    {
        // increase i
        do
        {
            i++;
        } while (arr[i] < pivot);

        // decrease j
        do
        {
            j--;
        } while (arr[j] > pivot);

        // base case
        if (i >= j)
            return j;

        // if base case is false swap i and j
        swap(arr[i], arr[j]);
    }
}

// QuickSort
void QuickSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int pivotIndex = hoarePartition(arr, low, high);
        QuickSort(arr, low, pivotIndex);
        QuickSort(arr, pivotIndex + 1, high);
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {8, 4, 7, 9, 3, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    QuickSort(arr, 0, n - 1);

    // Output
    for (int x : arr)
        cout << x << " ";
}