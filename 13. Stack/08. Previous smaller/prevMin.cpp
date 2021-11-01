/*
    Given an array of distinct integers, find its previous smaller array 
    (position-wise min and closest on the left side) of every array elements.
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// Find positionwise Smaller element in left O(n)
vi printPrevSmaller(int arr[], int n)
{
    // store answer
    vi res;

    // init stack
    stack<int> stk;

    // push first element
    stk.push(arr[0]);

    // positionwise left smallest for first is always -1
    res.push_back(-1);

    // logic:
    for (int i = 1; i < n; i++)
    {
        // pop from stack while stk.top() >= current element
        while (stk.empty() == false && stk.top() >= arr[i])
            stk.pop();

        // if stack is empty after pop => -1 otherwise stk.top()
        int val = stk.empty() ? -1 : stk.top();

        // push res in ans vector
        res.push_back(val);

        // push current element
        stk.push(arr[i]);
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    vi ans = printPrevSmaller(arr, n);

    // Output
    cout << "Previous smaller elements:\n";
    for (auto &val : ans)
        cout << val << " ";
}
