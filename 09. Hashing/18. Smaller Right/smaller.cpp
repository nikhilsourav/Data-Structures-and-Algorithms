/*
    Given an array arr[] of N elements. Count maximum number of
    distinct smaller elements on right side of any array element.

    eg:

    arr = {10, 6, 9, 7, 20, 19, 21, 18, 17, 16}
    output: 4

    Note that 20 has maximum 4 smaller elements on right side
    Other elements have less count, for example 10 has 3 smaller
    elements on right side.
*/

#include <bits/stdc++.h>
using namespace std;

// maximum count of smaller elements on right side.
int maxCount(vector<int> &arr)
{
    // init
    set<int> st;
    int res = 0;

    // start from end, insert each element, find max
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        st.insert(arr[i]);
        int dist = distance(st.begin(), st.find(arr[i]));
        cout << dist << " ";
        res = max(res, dist);
    }
    cout << endl;

    // ans
    return res;
}

// Driver code
int main()
{
    // Given vector
    vector<int> arr = {10, 6, 9, 7, 20, 19, 21, 18, 17, 16};

    // fn call
    cout << maxCount(arr);
}