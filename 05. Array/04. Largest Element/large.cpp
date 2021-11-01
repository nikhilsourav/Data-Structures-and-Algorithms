/*
    Find largest and second largest element in array
    eg: [1,0,7,3,6] 
    => largest element = 7, index = 2
    => second largest = 6, index = 4
*/

#include <bits/stdc++.h>
using namespace std;

// Return index of largest element
int largest(int *arr, int size)
{
    // initialize index
    int index = 0;

    // logic:
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[index])
            index = i;

    // return index or max value as required
    return index;
}

//  Return index of second largest element
int secondLargest(int *arr, int size)
{
    // init vars:
    int indexOfSecondLargest = -1, indexOfLargest = 0;

    // logic:
    for (int i = 1; i < size; i++)
    {
        // find largest and keep track of second largest
        if (arr[i] > arr[indexOfLargest])
        {
            indexOfSecondLargest = indexOfLargest;
            indexOfLargest = i;
        }
        else if (arr[i] != arr[indexOfLargest])
        {
            if (indexOfSecondLargest == -1 || arr[i] > arr[indexOfSecondLargest])
                indexOfSecondLargest = i;
        }
    }

    // return index
    return indexOfSecondLargest;
}

// Driver code;
int main()
{
    // Given array
    int arr[] = {7, 52, 91, 1, 72};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    int max = largest(arr, size);
    cout << "Largest element: " << arr[max] << "\n";
    int secMax = secondLargest(arr, size);
    cout << "Second largest element: " << arr[secMax] << "\n";
}