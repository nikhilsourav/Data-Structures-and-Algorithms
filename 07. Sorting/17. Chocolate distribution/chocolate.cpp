#include <bits/stdc++.h>
using namespace std;

// find min of difference betwen min and max in m elements
int minDiff(int arr[], int n, int m)
{
    // base case
    if (m > n)
        return -1;

    // sort given array
    sort(arr, arr + n);

    // initialize result
    int res = arr[m - 1] - arr[0];

    // logic:
    for (int i = 0; (i + m - 1) < n; i++)
        res = min(res, arr[i + m - 1] - arr[i]);
    
    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {7, 3, 2, 4, 9, 12, 56};
    int n = sizeof(arr) / sizeof(arr[0]);
    int m = 3;

    // fn call
    cout << minDiff(arr, n, m);
}