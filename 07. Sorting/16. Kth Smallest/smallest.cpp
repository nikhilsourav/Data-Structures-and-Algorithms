#include <bits/stdc++.h>
using namespace std;

// Lumato partition
int partition(int arr[], int l, int h)
{
    // init vars
    int pivot = arr[h]; // assuming pivot is last element
    int i = l - 1;

    // logic:
    for (int j = l; j <= h - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    // insert pivot at correct position
    swap(arr[i + 1], arr[h]);

    // answer
    return i + 1;
}

// kth smallest using lomuto partition
int KthSmallest(int arr[], int n, int k)
{
    // kth largest element is at arr[k-1] index in sorted array
    // init vars
    int left = 0, right = n - 1;

    // logic:
    while (right >= left)
    {
        // partition and get index
        int index = partition(arr, left, right);

        // if returned index is k-1 we got the result
        if (index == k - 1)
            return index;

        // if index > k-1 go left
        else if (index > k - 1)
            right = index - 1;

        // otherwise go right
        else
            left = index + 1;
    }

    // if not found
    return -1;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 4, 5, 8, 11, 6, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 4;

    // kth smallest element
    int index = KthSmallest(arr, n, k);
    cout << arr[index];
}