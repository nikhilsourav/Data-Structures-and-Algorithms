#include <bits/stdc++.h>
using namespace std;

// Previous greater element
vector<int> prevGreat(vector<int> arr)
{
    // init stack and vector
    stack<int> stk;
    vector<int> ans;

    // push last element
    stk.push(0);
    ans.push_back(0);

    // logic
    for (int i = 1; i < arr.size(); i++)
    {
        while ((!stk.empty()) and arr[stk.top()] <= arr[i])
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

// Next greater element
vector<int> nextGreat(vector<int> arr)
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
        while ((!stk.empty()) and arr[stk.top()] <= arr[i])
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

// Previous smaller element
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

// Next smaller element
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

// Print vector
void printIndex(vector<int> ar, string msg)
{
    cout << msg << "\n";
    for (auto &val : ar)
        cout << val << " ";
    cout << "\n\n";
}

// Driver code
int main()
{
    // Given arr
    vector<int> arr = {15, 10, 18, 12, 4, 6, 2, 8};

    // fn call
    vector<int> prevGrt = prevGreat(arr);
    vector<int> nextGrt = nextGreat(arr);
    vector<int> prevSml = prevSmall(arr);
    vector<int> nextSml = nextSmall(arr);

    // Print indices
    cout << "\n";
    printIndex(prevGrt, "Index of previous greater element:");
    printIndex(nextGrt, "Index of next greater element:");
    printIndex(prevSml, "Index of previous smaller element:");
    printIndex(nextSml, "Index of next smaller element:");

    // Print values
    cout << "\nValue of previous greater element:\n";
    for (auto &it : prevGrt)
    {
        if (it == 0)
            cout << -1 << " ";
        else
            cout << arr[it - 1] << " ";
    }

    cout << "\n\nValue of next greater element:\n";
    for (auto &it : nextGrt)
    {
        if (it == arr.size() - 1)
            cout << -1 << " ";
        else
            cout << arr[it + 1] << " ";
    }

    cout << "\n\nValue of previous smaller element:\n";
    for (auto &it : prevSml)
    {
        if (it == 0)
            cout << -1 << " ";
        else
            cout << arr[it - 1] << " ";
    }

    cout << "\n\nValue of next smaller element:\n";
    for (auto &it : nextSml)
    {
        if (it == arr.size() - 1)
            cout << -1 << " ";
        else
            cout << arr[it + 1] << " ";
    }
}