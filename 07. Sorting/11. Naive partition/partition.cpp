#include <bits/stdc++.h>
using namespace std;

// Naive partition (retains stability)
void partition(int arr[], int low, int high, int pivot)
{
    // init vars
    int temp[high - low + 1], index = 0;

    // copy smaller or equal elements:
    for (int i = low; i <= high; i++)
    {
        if (arr[i] <= arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    // copy larger elements
    for (int i = low; i <= high; i++)
    {
        if (arr[i] > arr[pivot])
        {
            temp[index] = arr[i];
            index++;
        }
    }

    // copy back to original array
    for (int i = low; i <= high; i++)
        arr[i] = temp[i - low];
}

// Driver code
int main()
{
    // given array
    int arr[] = {5, 13, 6, 9, 12, 11, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    partition(arr, 0, n - 1, n - 1);

    // output
    for (int x : arr)
        cout << x << " ";
}