/*
    Given an array. Find the Inversion Count in the array.

    Inversion Count: For an array, inversion count indicates
    how far (or close) the array is from being sorted. If
    array is already sorted then the inversion count is 0.
    If an array is sorted in the reverse order then the
    inversion count is the maximum.

    Formally, two elements a[i] and a[j] form an inversion
    if a[i] > a[j] and i < j.

    Input: N = 5, arr[] = {2, 4, 1, 3, 5}
    Output: 3

    Explanation: The sequence 2, 4, 1, 3, 5
    has three inversions (2, 1), (4, 1), (4, 3).

    https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
*/

#include <bits/stdc++.h>
using namespace std;

// Modified merge logic
int countAndMerge(int arr[], int low, int mid, int high)
{
    // initialize variables
    int n1 = mid - low + 1, n2 = high - mid;
    int left[n1], right[n2];

    // fill left and right array
    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];
    for (int i = 0; i < n2; i++)
        right[i] = arr[mid + i + 1];

    // merge logic:
    int i = 0, j = 0, res = 0, k = low;
    while (i < n1 && j < n2)
    {
        if (left[i] <= right[j])
            arr[k++] = left[i++];
        else
        {
            arr[k++] = right[j++];
            res += (n1 - i); // store count
        }
    }

    // remaining elements
    while (i < n1)
        arr[k++] = left[i++];
    while (j < n2)
        arr[k++] = right[j++];

    // return result
    return res;
}

// Recursive count inversion function
int countInv(int arr[], int low, int high)
{
    // res to store inv count
    int res = 0;

    // logic
    if (high > low)
    {
        int mid = low + (high - low) / 2;
        res += countInv(arr, low, mid);
        res += countInv(arr, mid + 1, high);
        res += countAndMerge(arr, low, mid, high);
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {2, 4, 1, 3, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << countInv(arr, 0, n - 1);
}