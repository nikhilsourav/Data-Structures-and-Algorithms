// https://www.youtube.com/watch?v=LjN2T7pg7WQ

#include <bits/stdc++.h>
using namespace std;

// check if array is increasing in range low to high
bool isIncreasing(int arr[], int low, int high)
{
    for (int i = low; i <= high - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;
    return true;
}

// check if array is decreasing in range low to high
bool isDecreasing(int arr[], int low, int high)
{
    for (int i = low; i <= high - 1; i++)
        if (arr[i] < arr[i + 1])
            return false;
    return true;
}

// check if array is increasing and rotated from minIndex to maxIndex
bool incAndRotated(int arr[], int n, int minIndex, int maxIndex)
{
    // if array is strictly increasing
    if (arr[0] < arr[n - 1])
        return false;

    // check increasing in range (0 to maxIndex) && (minIndex to n)
    return isIncreasing(arr, 0, maxIndex) && isIncreasing(arr, minIndex, n - 1);
}

// check if array is decreasing and rotated from minIndex to maxIndex
bool decAndRotated(int arr[], int n, int minIndex, int maxIndex)
{
    // if array is strictly decreasing
    if (arr[0] > arr[n - 1])
        return false;

    // check decreasing in range (0 to minIndex) && (maxIndex to n)
    return isDecreasing(arr, 0, minIndex) && isDecreasing(arr, maxIndex, n - 1);
}

// fn to check if array is sorted and rotated
bool checkRotatedAndSorted(int arr[], int n)
{
    // store index of Min and Max
    int minIndex = 0, maxIndex = 0;

    // find index of Min and Max in arr
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < arr[minIndex])
            minIndex = i;

        if (arr[i] > arr[maxIndex])
            maxIndex = i;
    }

    // init result
    bool res = false;

    // eg: [3, 4, 5, 1, 2]
    if (maxIndex == minIndex - 1)
        res = incAndRotated(arr, n, minIndex, maxIndex);

    // eg: [2, 1, 5, 4, 3]
    if (minIndex == maxIndex - 1)
        res = decAndRotated(arr, n, minIndex, maxIndex);

    // result
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {3, 4, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << boolalpha << checkRotatedAndSorted(arr, n);
}