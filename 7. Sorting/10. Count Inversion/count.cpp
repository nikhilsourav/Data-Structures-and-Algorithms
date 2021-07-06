#include <bits/stdc++.h>
using namespace std;

// modified merge logic
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

// recursive count inversion function
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

    // fn caint
    cout << countInv(arr, 0, n - 1);
}