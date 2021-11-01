/*
    Given an unsorted array of non-negative integers. Find if there is a subarray
    with given sum or not
*/
#include <bits/stdc++.h>
using namespace std;

// Sliding window technique
bool isSubSum(int arr[], int size, int sum)
{
    // init vars
    int currentSum = arr[0], start = 0;

    // logic
    for (int end = 1; end < size; end++)
    {
        // clean previous window
        while (currentSum > sum && sum < end - 1)
        {
            currentSum -= arr[start];
            start++;
        }

        // check if currSum is equal
        if (currentSum == sum)
            return true;

        // increase window
        if (end < size)
            currentSum += arr[end];
    }

    // answer
    return currentSum == sum;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 4, 20, 3, 10, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << isSubSum(arr, size, 33);
}