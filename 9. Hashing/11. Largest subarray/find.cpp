#include <bits/stdc++.h>
using namespace std;

// find largest subarray with given sum
int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    // init map
    unordered_map<int, int> prefixSum;

    // init vars:
    int currSum = 0, result = 0;

    // logic:
    for (int i = 0; i < n; i++)
    {
        // update current sum
        currSum += arr[i];

        // if current sum = given sum
        if (currSum == sum)
            result = i + 1;

        // if currSum doesn't exist already
        if (prefixSum.find(currSum) == prefixSum.end())
            prefixSum.insert({currSum, i});

        // if found
        if (prefixSum.find(currSum - sum) != prefixSum.end())
            result = max(result, i - prefixSum[currSum - sum]);
    }

    // answer
    return result;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {8, 3, 1, 5, -6, 6, 2, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 4;

    // fn call
    cout << largestSubarrayWithSumX(arr, n, sum);
}