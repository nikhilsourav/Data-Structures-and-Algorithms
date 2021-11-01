/*
    Print all possible subset of a given string.
    eg: ABC = [" ",  "C", "B", "BC", "A", "AC", "AB", "ABC"]

    For a string of length n, total possible subset = 2^n
*/

#include <bits/stdc++.h>
using namespace std;

// Print subset
void printSubset(string &str, string current, int index)
{
    // base case
    if (index == str.length())
    {
        cout << current << " ";
        return;
    }

    // recursion
    printSubset(str, current, index + 1);
    printSubset(str, current + str[index], index + 1);
}

// Driver code
int main()
{
    // Given string
    string s = "ABC";
    string current = "";

    // fn call
    printSubset(s, current, 0);
}