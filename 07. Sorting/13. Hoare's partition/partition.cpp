#include <bits/stdc++.h>
using namespace std;

// Hoare partition for quicksort
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

// Driver code
int main()
{
    // Given array
    int arr[] = {5, 3, 8, 4, 2, 7, 1, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    hoarePartition(arr, 0, n - 1);

    // Output
    for (int x : arr)
        cout << x << " ";
}