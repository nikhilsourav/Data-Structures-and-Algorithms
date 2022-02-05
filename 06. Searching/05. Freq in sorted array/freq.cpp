/*
    Given a sorted array and an element x,
    count occurrences of x in the array.
*/

#include <bits/stdc++.h>
using namespace std;

// Find index of first occurance
int indexOfFirst(int arr[], int size, int element)
{
    // init vars:
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > element)
            high = mid - 1;
        else if (arr[mid] < element)
            low = mid + 1;
        else
        {
            if (mid == 0 || arr[mid - 1] != arr[mid])
                return mid;
            else
                high = mid - 1;
        }
    }

    // if not found
    return -1;
}

// Find index of last occurance
int indexOfLast(int arr[], int size, int element)
{
    // init vars:
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (element > arr[mid])
            low = mid + 1;
        else if (element < arr[mid])
            high = mid - 1;
        else
        {
            if (mid == size - 1 || arr[mid + 1] != arr[mid])
                return mid;
            else
                low = mid + 1;
        }
    }

    // if not found
    return -1;
}

// Count frequency of given element log(n)
int countFrequency(int arr[], int size, int element)
{
    // index of first
    int first = indexOfFirst(arr, size, element);

    // if element not present
    if (first == -1)
        return 0;

    // index of last
    int last = indexOfLast(arr, size, element);

    // frequency = l - f + 1
    return (last - first + 1);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 10, 20, 20, 20, 40};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << countFrequency(arr, size, 10);
}