/*
    The task is to find maximum circular sum subarray of a given array.

    arr[] = {10, 5, -5}

    All normal subarrays: {10} {5} {-5} {10,5} {5,-5} {10,5,-5}
    Only circular subarrays: {5,-5,10} {-5,10} {-5,5,10}
*/

#include <bits/stdc++.h>
using namespace std;

// ======= Brute Force O(n^2) ===========
int maxCircularSum(int arr[], int size)
{
    // init result
    int res = arr[0];

    // logic:
    for (int i = 0; i < size; i++)
    {
        // init currentMax and currentSum
        int currMax = arr[i], currSum = arr[i];

        // check all subarray beginning with j
        for (int j = 1; j < size; j++)
        {
            int index = (i + j) % size;
            currSum += arr[index];
            currMax = max(currSum, currMax);
        }

        // update res
        res = max(currMax, res);
    }

    // answer
    return res;
}

// O(n) max in normal subarray using kadane's algo
int maxNormalSubarray(int arr[], int n)
{
    // init vars
    int res = arr[0], maxEnd = arr[0];

    // logic:
    for (int i = 1; i < n; i++)
    {
        maxEnd = max(maxEnd + arr[i], arr[i]);
        res = max(res, maxEnd);
    }

    // answer
    return res;
}

// min in normal subarray using modified kadane's algo
int minNormalSubarray(int arr[], int n)
{
    // init vars
    int minEnd = INT_MAX, res = INT_MAX;

    // logic:
    for (int i = 0; i < n; i++)
    {
        if (minEnd > 0)
            minEnd = arr[i];
        else
            minEnd += arr[i];
        res = min(res, minEnd);
    }

    // answer
    return res;
}

// overall max b/w these two
int efficientMaxCircularSum(int arr[], int n)
{
    // find max sum in normal subarray (kadane's algorithm)
    int normalMax = maxNormalSubarray(arr, n);
    if (normalMax < 0)
        return normalMax;

    // find max sum in only circular subarray (total_sum - min_sum_in_normal_subarray)
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    int circularMax = totalSum - minNormalSubarray(arr, n);

    // return max of both as final answer
    return max(normalMax, circularMax);
}

// Driver code
int main()
{
    // Given array
    int size = 4;
    int arr[size] = {5, -2, 3, 4};

    // fn call
    cout << maxCircularSum(arr, size) << "\n";
    cout << efficientMaxCircularSum(arr, size) << "\n";
}