/*
    Find maximum sub-array sum.
    eg: [1,-2,3, 0] => 3 {(3) or (3+0)}
*/

#include <bits/stdc++.h>
using namespace std;

//  Kadane's algorithm Time: O(n)
int maxSumEfficiently(int arr[], int size)
{
    // init vars:
    int res = arr[0], maxEnd = arr[0];

    // logic:
    for (int i = 1; i < size; i++)
    {
        maxEnd = max(maxEnd + arr[i], arr[i]);
        res = max(res, maxEnd);
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {-5, 1, -2, 3, -1, 2, -2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << maxSumEfficiently(arr, size) << "\n";
}