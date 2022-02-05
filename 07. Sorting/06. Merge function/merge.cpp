/*
    Given an array 'arr' and indices 'low', 'mid' and 'high'
    sort them and merge them back to original array

    Input
    arr[] = [1, 2, 4, 1000, 2000, 4000, 2000, 3000, 2, 3, 4]
    low = 3, mid = 5, high = 7

    Output
    arr[] = [1 2 4 1000 2000 2000 3000 4000 2 3 4]
*/

#include <bits/stdc++.h>
using namespace std;

// Merge function of merge sort
void merge(int arr[], int low, int mid, int high)
{
    // init vars
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];

    // fill left array
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    // fill right array
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];

    // merge logic
    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }

    // remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];
}

// Driver code
int main()
{
    // Given array
    int arr[] = {20, 6, 14, 1000, 2000, 4000, 2000, 3000, 52, 3, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 3, mid = 5, high = 7;

    // fn call (merge from index 3 to 7)
    merge(arr, low, mid, high);

    // Output
    for (auto x : arr)
        cout << x << " ";
}