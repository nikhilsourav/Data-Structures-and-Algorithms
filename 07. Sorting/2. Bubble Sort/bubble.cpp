/*
    * O(n^2) algorithm
    * Stable
*/

#include <bits/stdc++.h>
using namespace std;

// bubble sort
void bubbleSort(int arr[], int size)
{
    // normal
    for (int i = 0; i < size - 1; i++)
        for (int j = 0; j < size - i - 1; j++)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

    return;

    // optimized
    for (int i = 0; i < size - 1; i++)
    {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }

    return;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {8, 2, 1, 9, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    bubbleSort(arr, size);

    // output
    for (auto x : arr)
        cout << x << " ";
}