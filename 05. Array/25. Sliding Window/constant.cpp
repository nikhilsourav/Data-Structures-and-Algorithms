/*
    Given an array and a number k, find max sum of k consecutive elements
    **  WINDOW SIZE IS CONSTANT  **
    https://www.youtube.com/watch?v=jM2dhDPYMQM
*/

#include <bits/stdc++.h>
using namespace std;

// sliding window of fixed size
int maxSum(int arr[], int size, int k)
{
    // initialize variables
    int sum = 0, maxim = INT_MIN;

    // calculate sum for first window
    for (int i = 0; i < k; i++)
        sum += arr[i];
    maxim = sum;

    // calculate sum for subsequent windows
    for (int i = k; i < size; i++)
    {
        sum += (arr[i] - arr[i - k]);
        maxim = max(maxim, sum);
    }

    // return result
    return maxim;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 8, 30, -5, 20, 7};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // fn call
    cout << maxSum(arr, size, k);
}