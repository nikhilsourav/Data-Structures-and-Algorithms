/*
    Given an array of distinct integers, find the 
    prevGreater(position-wise max and closest on the left side) 
    of every array elements.
    This is base for pge, nge, pse, nse 
*/
#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// fn to find positionwise greater element in left O(n)
vi printPrevGreater(int arr[], int n)
{
    // store answer
    vi res;

    // init stack
    stack<int> stk;

    // push first element
    stk.push(arr[0]);

    // positionwise left greatest for first is always -1
    res.push_back(-1);

    // logic:
    for (int i = 1; i < n; i++)
    {
        // pop from stack while stk.top() <= current element
        while (stk.empty() == false && stk.top() <= arr[i])
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
    vi ans = printPrevGreater(arr, n);

    // output
    cout << "Previous greator elements:\n";
    for (auto &val : ans)
        cout << val << " ";
}
