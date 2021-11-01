/*
    Given an array of integers representing prices of a stock on n consecutive days.
    Find span of stock on each day. Span on a day is number of consecutive days including
    current day and days just before it which have value equal or smaller.
    eg: [13,15,12,14,16,8,6,4,10,13] => [1,2,1,2,5,1,1,1,4,10] 
*/

#include <bits/stdc++.h>
using namespace std;

// Find span of each element
vector<int> printSpan(int arr[], int n)
{
    // store answer
    vector<int> result;

    // init stack;
    stack<int> stk;

    // first element's span is always 1
    stk.push(0);
    result.push_back(1);

    // logic:
    for (int i = 1; i < n; i++)
    {
        // check if stack empty
        while (stk.empty() == false && arr[stk.top()] <= arr[i])
            stk.pop();

        // calculate span and print
        int span = stk.empty() ? i + 1 : i - stk.top();
        result.push_back(span);

        // push current element
        stk.push(i);
    }

    // return 
    return result;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {18, 12, 13, 14, 11, 16};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    vector<int> ans = printSpan(arr, n);

    // Output
    for (auto &val : ans)
        cout << val << " ";
}
