/*
    Check if two strings are rotation of each other
*/

#include <bits/stdc++.h>
using namespace std;

// Check
bool areRotations(string s1, string s2)
{
    return (s1.length() == s2.length()) && ((s1 + s1).find(s2) != string::npos);
}

int main()
{
    // Given string
    string s1 = "ABCD", s2 = "CDAB";

    // fn call
    cout << boolalpha << areRotations(s1, s2);
}