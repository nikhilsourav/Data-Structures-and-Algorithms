/*
    * O(n^2) algorithm
    * Does less memory write as compared to Quick sort, Merge sort, insertion sort etc
    * In terms of less memory write cycle sort is best
    * Not stable
    * In place
    * Basic idea for heap sort
*/

#include <bits/stdc++.h>
using namespace std;

// Selection sort
void selectionSort(int *arr, int size)
{
    // logic:
    for (int i = 0; i < size - 1; i++)
    {
        // min will sotre index of min element
        int min_index = i;

        // find index of min element
        for (int j = i + 1; j < size; j++)
            if (arr[j] < arr[min_index])
                min_index = j;

        // swap current index (i) with min element
        swap(arr[i], arr[min_index]);
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 5, 8, 20, 2, 18};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    selectionSort(arr, size);

    // output
    for (auto x : arr)
        cout << x << " ";
}