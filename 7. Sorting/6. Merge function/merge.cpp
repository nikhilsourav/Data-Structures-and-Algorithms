#include <bits/stdc++.h>
using namespace std;

// merge function of merge sort
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
    int arr[] = {1, 2, 4, 1000, 2000, 4000, 2000, 3000, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call (merge from index 3 to 7)
    merge(arr, 3, 5, 7);

    // output
    for (auto x : arr)
        cout << x << " ";
}