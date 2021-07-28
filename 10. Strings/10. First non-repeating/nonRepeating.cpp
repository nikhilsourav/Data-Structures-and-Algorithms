#include <bits/stdc++.h>
using namespace std;

// Global CHAR size
const int CHAR = 256;

// Approach 1 Two traversal Time: O(n), Space: O(CHAR)
int nonRep(string &str)
{
    // init count array
    int count[CHAR] = {0};

    // count all characters
    for (int i = 0; i < str.length(); i++)
        count[str[i]]++;

    // if count is 1 it's first non repeating
    for (int i = 0; i < str.length(); i++)
        if (count[str[i]] == 1)
            return i;

    // if not found
    return -1;
}

// Approach 2. One traversal Time: O(n + CHAR), Space: O(CHAR)
int firstNonRepeating(string &str)
{
    // store first index
    int firstIndex[CHAR];

    // fill this array with -1
    fill(firstIndex, firstIndex + CHAR, -1);

    // logic
    for (int i = 0; i < str.length(); i++)
    {
        if (firstIndex[str[i]] == -1)
            firstIndex[str[i]] = i;
        else
            firstIndex[str[i]] = -2;
    }

    // init result
    int res = INT_MAX;

    // find minimum in firstIndex array
    for (int i = 0; i < CHAR; i++)
        if (firstIndex[i] >= 0)
            res = min(res, firstIndex[i]);

    // return answer
    return (res == INT_MAX) ? -1 : res;
}

// Driver code
int main()
{
    // Given string
    string str = "abbcbda";

    // fn call
    cout << firstNonRepeating(str);
}