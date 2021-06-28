/*
    Given a binary array, we need to find the 
    minimum of number of group flips to make all array elements same.
    In a group flip, we can flip any set of consecutive 1s or 0s.
*/
#include <bits/stdc++.h>
using namespace std;

// Time complexity: O(n)
void printGroups(int arr[], int size)
{
    // Logic:
    for (int i = 1; i < size; i++)
    {
        if (arr[i] != arr[i - 1])
        {
            if (arr[i] != arr[0])
                cout << "From " << i << " to ";
            else
                cout << (i - 1) << "\n";
        }
    }

    // Print:
    if (arr[size - 1] != arr[0])
        cout << (size - 1) << "\n";
}

// Driver code
int main()
{

    // Given array
    int arr[] = {0, 0, 1, 1, 0, 0, 1, 1, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    printGroups(arr, size);
}