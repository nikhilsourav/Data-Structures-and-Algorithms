/*
    Improved Naive pattern searching 
*/

#include <bits/stdc++.h>
using namespace std;

// Optimized pattern search
void findPattern(string &str, string &pattern)
{
    // init size
    int strSize = str.size(), patternSize = pattern.size();

    // logic:
    for (int low = 0; low <= (strSize - patternSize);)
    {
        // init end pointer
        int high = 0;

        // loop untill matching
        for (high = 0; high < patternSize; high++)
            if (str[low + high] != pattern[high])
                break;

        // if high crossed pattern size
        if (high == patternSize)
            cout << "Found at index " << low << "\n";

        // if first character mismatch
        if (high == 0)
            low++;
        // if any subsequent character mismatch
        else
            low = (low + high);
    }
}

// Driver code
int main()
{
    // Given string
    string str = "ABCEABEFABCD";
    string pattern = "ABCD";

    // Optimized naive pattern search
    findPattern(str, pattern);
}