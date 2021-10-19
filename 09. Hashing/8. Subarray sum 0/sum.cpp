#include <bits/stdc++.h>
using namespace std;

// check if there is a subarray with sum 0
bool ZeroSumSubarray(int arr[], int n)
{
    // init set
    unordered_set<int> prefixSum;
    prefixSum.insert(0);

    // init var:
    int currentSum = 0;
    for (int i = 0; i < n; i++)
    {
        // update current sum
        currentSum += arr[i];

        // check if sum is there or not
        if (prefixSum.find(currentSum) != prefixSum.end())
            return true;

        // insert current sum
        prefixSum.insert(currentSum);
    }

    // if no such subarray
    return false;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    ZeroSumSubarray(arr, n) ? cout << "True" : cout << "False";
}