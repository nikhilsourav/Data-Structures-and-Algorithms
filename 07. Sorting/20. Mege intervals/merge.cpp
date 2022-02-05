/*
    Given an array of intervals where intervals[i] = [starti, endi],
    merge all overlapping intervals, and return an array of the non
    overlapping intervals that cover all the intervals in the input.

    Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
    Output: [[1,6],[8,10],[15,18]]

    Explanation: Since intervals [1,3] and [2,6] overlaps,
    merge them into [1,6].
    
    https://leetcode.com/problems/merge-intervals/
*/

#include <bits/stdc++.h>
using namespace std;

// Utility function
void output(vector<vector<int>> arr)
{
    // output vector
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
            cout << arr[i][j] << " ";
        cout << "\n";
    }
}

// Merge intervals
vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    // edge case
    if (intervals.size() <= 1)
        return intervals;

    // init answer vector
    vector<vector<int>> answer;

    // sort
    sort(intervals.begin(), intervals.end());

    // logic:
    answer.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++)
    {
        if (answer.back()[1] >= intervals[i][0])
            answer.back()[1] = max(answer.back()[1], intervals[i][1]);
        else
            answer.push_back(intervals[i]);
    }

    // return answer
    return answer;
}

// Driver code
int main()
{
    // Given interval
    vector<vector<int>> intervals = {{5, 10}, {3, 15}, {18, 30}, {2, 7}};

    // fn call
    vector<vector<int>> answer = mergeIntervals(intervals);

    // Output
    output(answer);
}