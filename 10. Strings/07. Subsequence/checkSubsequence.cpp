/*
    Check if s2 is subsequence of s1
    eg: s1 = "abcde", s2 = "ace" => true
*/

#include <bits/stdc++.h>
using namespace std;

// Check
bool isSubsequence(string s1, string s2)
{
    // init pointer to keep track of each char in s2
    int ptr = 0;

    // if ch = s1[ptr] move both pointer otherwise only ch
    for (auto ch : s1)
        if (ch == s2[ptr])
            ptr++;

    // if ptr == s2.size(), every char of s2 appear in s1
    return ptr == s2.size();
}

// Driver code
int main()
{
    // Given string
    string s1 = "GEEKSFORGEEKS", s2 = "SKS";

    // fn call
    cout << boolalpha << isSubsequence(s1, s2);
}