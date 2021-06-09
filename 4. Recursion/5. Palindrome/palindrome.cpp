#include <bits/stdc++.h>
using namespace std;

// check palindrome using recursion
bool checkPalindrome(string str, int start, int end)
{
    // base case
    if (start >= end)
        return true;
    // fn call
    if (str[start] == str[end])
        return checkPalindrome(str, start + 1, end - 1);

    // if not palindrome
    return false;
}

// code cleaned
bool isPalindrome(string str, int start, int end)
{
    // base case
    if (start >= end)
        return true;

    // fn call
    return ((str[start] == str[end]) && isPalindrome(str, start + 1, end - 1));
}

// Driver code
int main()
{
    // Given string
    string s = "racecar";

    // fn call
    cout << (checkPalindrome(s, 0, s.length() - 1) ? "Palindrome" : "Not Palindrome");
}