#include <bits/stdc++.h>
using namespace std;

// merge array
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

// merge sort
void mergeSort(int arr[], int left, int right)
{

    if (right > left)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Driver code;
int main()
{
    // Given array
    int arr[] = {10, 5, 30, 15, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    mergeSort(arr, 0, n - 1);

    // output
    for (auto x : arr)
        cout << x << " ";
}