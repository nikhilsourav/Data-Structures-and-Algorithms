/*
    Given an array of non-negative integers where each value represents height of
    each building. Find total amount of water that can be collected between the
    buildings. Notice that the leftmost and rightmost building can't hold any
    amount of water.
    eg: [8,8,2,4,5,5,1]
    => between 8 and 5 = {(5-2) + (5-4)} = 4
*/

#include <bits/stdc++.h>
using namespace std;

// Time: O(n^2) Space: O(1)
int trappedWater(int *arr, int size)
{
    // init vars:
    int res = 0;

    // logic:
    for (int i = 1; i < size - 1; i++)
    {
        // find left max
        int lmax = arr[i];
        for (int j = 0; j < i; j++)
            lmax = max(lmax, arr[j]);

        // find right max
        int rmax = arr[i];
        for (int j = i + 1; j < size; j++)
            rmax = max(rmax, arr[j]);

        // calculate res
        res += min(lmax, rmax) - arr[i];
    }

    // answer
    return res;
}

// Time: O(n), Space: O(n)
int trappedWaterEfficient(int arr[], int size)
{
    // init vars:
    int res = 0;
    int lmax[size], rmax[size];

    // compute lmax
    lmax[0] = arr[0];
    for (int i = 1; i < size; i++)
        lmax[i] = max(arr[i], lmax[i - 1]);

    // compute rmax
    rmax[size - 1] = arr[size - 1];
    for (int i = size - 2; i >= 0; i--)
        rmax[i] = max(arr[i], rmax[i + 1]);

    // compute result
    for (int i = 1; i < size - 1; i++)
        res += min(lmax[i], rmax[i]) - arr[i];

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {8, 8, 2, 4, 5, 5, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << trappedWater(arr, size);
}