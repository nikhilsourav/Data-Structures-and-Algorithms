/*
    Remove duplicates from a sorted array
    eg: [1, 2, 3, 3, 4, 5, 5, 8, 8] => [1, 2, 3, 4, 5, 8]
*/

#include <bits/stdc++.h>
using namespace std;

// Remove duplicate from sorted array and return the new size
int removeDuplicates(int *arr, int size)
{
    // init vars
    int newSize = 1;

    // logic:
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[newSize - 1])
        {
            arr[newSize] = arr[i];
            newSize++;
        }
    }

    // answer
    return newSize;
}

// Remove duplicates using two pointer
int removeDups(int arr[], int n)
{
    // init vars
    int i = 0;

    // logic: pointer i will travel slower than pointer j
    for (int j = 1; j < n; ++j)
    {
        if (arr[j] != arr[i])
        {
            i++;
            arr[i] = arr[j];
        }
    }

    // return result
    return (i + 1);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 3, 4, 5, 5, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Before any removal
    cout << "--------- before ----------\n";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";

    // Array is rearranged thus print from 0 to newSize
    int newSize = removeDups(arr, size);

    // Print result after removal
    cout << "---------- after ----------\n";
    for (int i = 0; i < newSize; i++)
        cout << arr[i] << " ";
}