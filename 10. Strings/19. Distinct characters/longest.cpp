#include <bits/stdc++.h>
using namespace std;

// longest subarray with all distinct characters
int longestDistinct(string str)
{
    // init size and res
    int n = str.size(), res = 0;

    // init vector
    vector<int> prev(256, -1);

    // logic:
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        i = max(i, prev[str[j]] + 1);
        int maxEnd = j - i + 1;
        res = max(res, maxEnd);
        prev[str[j]] = j;
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given string
    string str = "geeksforgeeks";

    // fn call
    cout << longestDistinct(str);
}
