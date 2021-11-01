#include <bits/stdc++.h>
using namespace std;

// Lumato partition for quicksort
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

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 80, 30, 90, 40, 50, 70};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    lomutoPartition(arr, 0, n - 1);

    // Output
    for (int x : arr)
        cout << x << " ";
}