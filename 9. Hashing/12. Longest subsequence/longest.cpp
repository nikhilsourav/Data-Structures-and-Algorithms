#include <bits/stdc++.h>
using namespace std;

// find lenght of longest consecutive subsequence
int findLongest(int arr[], int n)
{
    // init set
    unordered_set<int> s(arr, arr + n);

    // init result
    int res = 0;

    // logic:
    for (int i = 0; i < n; i++)
    {
        // count subsequence ane update res
        if (s.find(arr[i] - 1) == s.end())
        {
            int curr = 1;
            while (s.find(curr + arr[i]) != s.end())
                curr++;

            res = max(res, curr);
        }
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << findLongest(arr, n);
}