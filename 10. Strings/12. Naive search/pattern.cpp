#include <bits/stdc++.h>
using namespace std;

// Naive pattern search Time: O((n-m+1)*m)
void findPattern(string &str, string &pattern)
{
    // init size
    int strSize = str.size(), patternSize = pattern.size();

    // logic:
    for (int low = 0; low <= strSize - patternSize; low++)
    {
        // init end pointer
        int high = 0;

        // loop while matching
        for (high = 0; high < patternSize; high++)
            if (str[low + high] != pattern[high])
                break;

        // if high crossed patternSize
        if (high == patternSize)
            cout << "Found at index " << low << "\n";
    }
}

// Driver code
int main()
{
    // Given string
    string str = "abababcxyabcklabc", pattern = "abc";

    // fn call
    findPattern(str, pattern);
}