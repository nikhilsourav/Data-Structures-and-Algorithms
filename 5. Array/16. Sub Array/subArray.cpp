/*
    Subarrays are arrays within another array.
    Subarrays contains contiguous elements whereas subsequences are not.
    Substrings are similar to subarray but for strings
*/

/*
    A subbarray is a contiguous part of array.
    An array that is inside another array. 
    For example, consider the array [1, 2, 3, 4], 
    There are 10 non-empty sub-arrays. (maintaining the order of elements).
    The subbarays are (1), (2), (3), (4), (1,2), (2,3), (3,4), (1,2,3), (2,3,4) and (1,2,3,4). 
    In general, for an array/string of size n, there are n*(n+1)/2 non-empty subarrays/subsrings.
*/

#include <bits/stdc++.h>
using namespace std;

// print all non-empty subarray
void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = i; k <= j; k++)
                cout << arr[k] << " ";
            cout << "\n";
        }
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    print(arr, n);
}