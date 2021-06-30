/*
    find index of first occurance in a sorted array
*/
#include <bits/stdc++.h>
using namespace std;

// Iterative method Time: O(log n), Space: O(1)
int firstOccuranceIterative(int arr[], int size, int element)
{
    // normal binary search
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        // normal binary search
        int mid = (low + high) / 2;

        if (arr[mid] > element)
            high = mid - 1;

        else if (arr[mid] < element)
            low = mid + 1;

        // extra case to handle equal elements
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid]) // in this case mid is first occurance
                return mid;
            else
                high = mid - 1; // go to left half
        }
    }

    // if not found
    return -1;
}

// Recursive method Time: O(log n), Space: O(log n)
int firstOccuranceRecursive(int arr[], int low, int high, int element)
{
    // normal binary search
    if (low > high)
        return -1;

    int mid = (low + high) / 2;

    if (element > arr[mid])
        return firstOccuranceRecursive(arr, mid + 1, high, element);
    else if (element < arr[mid])
        return firstOccuranceRecursive(arr, low, mid - 1, element);

    // extra case to handle equal elements
    else
    {
        if (mid == 0 || (arr[mid - 1] != arr[mid])) // check if mid is first occurance
            return mid;
        else
            return firstOccuranceRecursive(arr, low, mid - 1, element); // if not, go to left half
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 1, 2, 2, 3, 5, 5, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    int number = 2;
    cout << firstOccuranceIterative(arr, size, number) << " \n";
    cout << firstOccuranceRecursive(arr, 0, size - 1, number);
}