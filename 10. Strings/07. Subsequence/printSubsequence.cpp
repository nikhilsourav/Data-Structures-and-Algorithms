/*
    Print all subsequence of given string
*/

#include <bits/stdc++.h>
using namespace std;

// Print subsequence
void subSeq(string ans, string str, int low, int high)
{
    // base case
    if (low == high)
        cout << ans << " ";
    // tree recursion
    else
    {
        // don't include
        subSeq(ans, str, low + 1, high);

        // add element to ans
        ans += str[low];

        // include ans
        subSeq(ans, str, low + 1, high);
    }
}

// Driver code
int main()
{
    // Given string
    string str = "ABC";

    // fn call
    subSeq("", str, 0, str.size());
}