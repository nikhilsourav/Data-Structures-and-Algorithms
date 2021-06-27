/*
    Given an array(0-based indexing), 
    you have to find the max sum of i*A[i] 
    where A[i] is the element at index i in the array. 
    The only operation allowed is to rotate(clock-wise or counter clock-wise) 
    the array any number of times.

    explaination : https://www.youtube.com/watch?v=3YNs_Ggqb-Q&t=32s
*/
#include <bits/stdc++.h>
using namespace std;

// Max sum of (arr[i]*i) O(n)
int maxSum(int arr[], int size)
{
    // sum of all element in arr
    int temp = 0;
    int sum = accumulate(arr, arr + size, temp);

    // find maximum of i*arr[i] from 1 to n-1 for current arr (without rotation)
    int maximum = 0;
    for (int i = 1; i < size; ++i)
        maximum += (i)*arr[i];

    // init res var
    int res = maximum;

    // check for all subsequent rotation and update res
    for (int i = 1; i < size; ++i)
    {
        maximum = maximum - (sum - arr[i - 1]) + (arr[i - 1] * (size - 1));
        res = max(res, maximum);
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {8, 3, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << maxSum(arr, n);
}