/*
    Check whether a string is palindrome or not
    eg: str = "aba" => true
*/

#include <bits/stdc++.h>
using namespace std;

// Check palindrome
bool isPalindrome(string str)
{
    // init vars:
    int low = 0, high = str.size() - 1;

    // logic:
    while (low <= high)
        if (str[low++] != str[high--])
            return false;

    // answer
    return true;
}

// Driver code
int main()
{
    // Given string
    string str = "abbbba";

    // fn call
    isPalindrome(str) ? cout << "True" : cout << "False";
}