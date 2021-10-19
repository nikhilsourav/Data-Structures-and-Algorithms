/*
    Given an array and sum, check whether a subarray contains the sum or not
    **  WINDOW SIZE IS VARIABLE  **
    https://www.youtube.com/watch?v=jM2dhDPYMQM
*/

#include <bits/stdc++.h>
using namespace std;

// Function to print subarray having a given sum using sliding window technique
void findSubarray(int arr[], int n, int givenSum)
{
    // maintains the sum of the current window
    int windowSum = 0;

    // maintain a window `[low, high-1]`
    int low = 0, high = 0;

    // consider every subarray starting from the `low` index
    for (low = 0; low < n; low++)
    {
        // if the current window's sum is less than the given sum,
        // then add elements to the current window from the right
        while (windowSum < givenSum && high < n)
        {
            windowSum += arr[high];
            high++;
        }

        // if the current window's sum is equal to the given sum
        if (windowSum == givenSum)
        {
            cout << "Subarray found " << low << " " << high - 1 << "\n";
            return;
        }

        // At this point, the current window's sum is more than the given sum.
        // Remove the current element (leftmost element) from the window
        windowSum -= arr[low];
    }
}

int main()
{
    // Given array
    int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 9;

    // fn call
    findSubarray(arr, n, sum);
}