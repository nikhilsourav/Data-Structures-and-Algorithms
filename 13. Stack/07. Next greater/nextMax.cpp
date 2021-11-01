/*
    Given an array of distinct integers, find its next greater array 
    (position-wise max and closest on the right side) of every array elements.
*/

#include <bits/stdc++.h>
using namespace std;
#define vi vector<int>

// Find positionwise greater element in right
vi printNextGreater(int arr[], int n)
{
    // store answer
    vi res;

    // init stack
    stack<int> stk;

    // push last element
    stk.push(arr[n - 1]);

    // positionwise greatest on right for last is always -1
    res.push_back(-1);

    // logic:
    for (int i = n - 2; i >= 0; i--)
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

    // answer is in reverse
    reverse(res.begin(), res.end());
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    vi ans = printNextGreater(arr, n);

    // Output
    cout << "Next greator elements:\n";
    for (auto &val : ans)
        cout << val << " ";
}
