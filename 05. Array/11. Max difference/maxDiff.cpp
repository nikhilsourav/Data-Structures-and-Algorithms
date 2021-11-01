/*
    Find the maximum of arr[j] - arr[i] where j>i.
    eg: [2, 3, 10, 6, 4, 8, 1], maxDiff = 10 - 2 = 6
*/

#include <bits/stdc++.h>
using namespace std;

//  Modified Kadane's algorithm
int maxDiff(int arr[], int size)
{
    // init vars:
    int res = arr[1] - arr[0], minVal = arr[0];

    // logic:
    for (int j = 1; j < size; j++)
    {
        res = max(res, arr[j] - minVal);
        minVal = min(minVal, arr[j]);
    }

    // answer
    return res;
}

// Different way to write same logic
int maxDifference(int arr[], int size)
{
    // can also be written as
    int max = arr[1] - arr[0], minValue = arr[0];

    // logic:
    for (int j = 1; j < size; j++)
    {
        if (arr[j] - minValue > max)
        {
            max = arr[j] - minValue; // update max
            minValue = arr[j];       // update min value
        }
    }

    // answer
    return max;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {2, 3, 10, 6, 4, 8, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << maxDiff(arr, size);
}