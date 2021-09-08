// https://leetcode.com/problems/largest-rectangle-in-histogram/

#include <bits/stdc++.h>
using namespace std;

// =============== max area of histogram O(n^2) ================= //
int getMaxArea(int arr[], int n)
{
    // to store maximum area
    int maxim = INT_MIN;

    // logic:
    for (int i = 0; i < n; i++)
    {
        // init vars
        int currArea = arr[i], count = 0;

        // for each arr[i] check left
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] >= arr[i])
                count++;
            else
                break;
        }

        // for each arr[i] check right
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] >= arr[i])
                count++;
            else
                break;
        }

        // currArea = (curr elem) + (total count * arr[i])
        currArea += count * arr[i];

        // update maxim
        maxim = max(maxim, currArea);
    }

    // return
    return maxim;
}

// ================ max area of histogram O(n) =================== //
// previous smaller element
vector<int> prevSmall(vector<int> arr)
{
    // init stack and vector
    stack<int> stk;
    vector<int> ans;

    // push first element
    stk.push(0);
    ans.push_back(0);

    // logic
    for (int i = 1; i < arr.size(); i++)
    {
        while (!stk.empty() and arr[stk.top()] >= arr[i])
            stk.pop();

        if (stk.empty())
            ans.push_back(0);
        else
            ans.push_back(stk.top() + 1);

        stk.push(i);
    }

    // answer
    return ans;
}

// next smaller element
vector<int> nextSmall(vector<int> arr)
{
    // init stack and vector
    stack<int> stk;
    vector<int> ans;

    // push last element
    stk.push(arr.size() - 1);
    ans.push_back(arr.size() - 1);

    // logic
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        while ((!stk.empty()) and arr[stk.top()] >= arr[i])
            stk.pop();

        if (stk.empty())
            ans.push_back(arr.size() - 1);

        else
            ans.push_back(stk.top() - 1);

        stk.push(i);
    }

    // reverse
    reverse(ans.begin(), ans.end());

    // answer
    return ans;
}

// Given function
int largestRectangleArea(vector<int> arr)
{
    // init vars
    stack<int> stk;
    int n = arr.size();

    // fill left small and right small vector
    vector<int> left = prevSmall(arr);
    vector<int> right = nextSmall(arr);

    // calculate max area
    int max_area = INT_MIN;
    for (int i = 0; i < n; i++)
        max_area = max(max_area, ((right[i] - left[i] + 1) * arr[i]));

    // reuturn
    return max_area;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {15, 10, 18, 12, 4, 6, 2, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vrr(arr, arr + n);

    // fn call
    cout << "Maximum Area: " << getMaxArea(arr, n);
    cout << "\nMaximum Area: " << largestRectangleArea(vrr);
}
