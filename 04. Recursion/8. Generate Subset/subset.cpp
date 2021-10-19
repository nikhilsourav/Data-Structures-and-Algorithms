#include <bits/stdc++.h>
using namespace std;

// print subset
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