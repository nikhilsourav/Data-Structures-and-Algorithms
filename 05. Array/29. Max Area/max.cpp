/*
    Container with most water
    https://leetcode.com/problems/container-with-most-water/
*/

#include <bits/stdc++.h>
using namespace std;

// Find max area of water
int maxArea(vector<int> &height)
{
    // init vars:
    int i = 0, j = height.size() - 1, maxArea = INT_MIN;

    // logic:
    while (i < j)
    {
        // init minimum height
        int high = min(height[i], height[j]);

        // compute maxArea with current minimum height
        maxArea = max(maxArea, high * (j - i));

        // increment first pointer
        while (height[i] <= high && i < j)
            i++;

        // decrement second pointer
        while (height[j] <= high && i < j)
            j--;
    }

    // result
    return maxArea;
}

// Driver code
int main()
{
    // Given vector
    vector<int> arr{1, 8, 6, 2, 5, 4, 8, 3, 7};

    // fn call
    cout << maxArea(arr);
}