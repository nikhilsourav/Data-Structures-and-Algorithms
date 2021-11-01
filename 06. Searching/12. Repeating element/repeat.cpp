/*
    Every element appear exactly ones except one element.
    This one element may repeat any number of times
*/

#include <bits/stdc++.h>
using namespace std;

// Find duplicate number
int repeating(int arr[], int size)
{
    // phase 1
    int slow = arr[0], fast = arr[0];
    do
    {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);

    // phase 2
    slow = arr[0];
    while (slow != fast)
    {
        slow = arr[slow];
        fast = arr[fast];
    }

    // solution
    return slow;
}

// Find only repeating element and its freq in sorted array
pair<int, int> findRepeatingElement(int arr[], int n)
{
    // corner case
    if (n == 0)
        return {0, 0};

    // initialize low and high vars
    int low = 0, high = n - 1;

    // logic
    while (low < high)
    {
        int mid = (low + high) / 2;

        // if arr[mid] = mid + arr[0], there is no repeating character in [low..mid]
        if (arr[mid] >= mid + arr[0])
            low = mid + 1;

        // if arr[mid] < mid + arr[0], there is a repeating character in [low..mid]
        else
            high = mid;
    }

    // return answer
    return {arr[low], n - (arr[n - 1] - arr[0])};
}

// Driver code
int main()
{
    // Given array
    int arr[] = {2, 4, 1, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << repeating(arr, size) << "\n";

    // Given array
    int arr1[] = {1, 2, 3, 3, 4};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    // fn call
    cout << findRepeatingElement(arr1, n).first << " " << findRepeatingElement(arr1, n).second;
}