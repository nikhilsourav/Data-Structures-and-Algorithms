#include <bits/stdc++.h>
using namespace std;

// return index of largest element
int largest(int *arr, int size)
{
    // initialize index
    int index = 0;

    // logic
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[index])
            index = i;

    // return index or max value as required
    return index;
}

//  return index of second largest element
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
    int size = 6;
    int arr[size] = {7, 52, 91, 1, 72};

    // fn call
    int max = largest(arr, size);
    cout << "Largest element: " << arr[max] << "\n";
    int secMax = secondLargest(arr, size);
    cout << "Second largest element: " << arr[secMax] << "\n";
}