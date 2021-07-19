#include <bits/stdc++.h>
using namespace std;

// count subarray with sum = k
int subarraySumEqualK(vector<int> arr, int k)
{
    // init map:
    unordered_map<int, int> prefixSum;
    prefixSum.insert({0, 1});

    // logic:
    int currentSum = 0, count = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        // calculate subarray sum
        currentSum += arr[i];

        // if currSum - k already present increment count
        if (prefixSum.find(currentSum - k) != prefixSum.end())
            count += prefixSum[currentSum - k];

        // insert new value
        prefixSum[currentSum]++;
    }

    // answer
    return count;
}

// Find the number of subarrays having equal number of 0s and 1s.
long long countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    // replace all 0 with -1 in given array
    vector<int> replacedWithOne;

    // replaced
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
            replacedWithOne.push_back(-1);
        else
            replacedWithOne.push_back(1);
    }

    // call for subarray with sum k, here k = 0
    return subarraySumEqualK(replacedWithOne, 0);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 0, 0, 1, 0, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << countSubarrWithEqualZeroAndOne(arr, n);
}