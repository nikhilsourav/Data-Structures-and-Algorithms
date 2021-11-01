#include <bits/stdc++.h>
using namespace std;

// Quicksort using lomuto partition
int lomutoPartition(int arr[], int low, int high)
{
    // init vars
    int pivot = arr[high]; // assuming pivot is last element
    int i = low - 1;

    // logic:
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // insert pivot at correct position
    swap(arr[i + 1], arr[high]);

    // answer
    return i + 1;
}

// Quick sort
void QuickSort(int arr[], int low, int high)
{
    if (high > low)
    {
        int pivotIndex = lomutoPartition(arr, low, high);
        QuickSort(arr, low, pivotIndex - 1);
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

    // output
    for (int x : arr)
        cout << x << " ";
}