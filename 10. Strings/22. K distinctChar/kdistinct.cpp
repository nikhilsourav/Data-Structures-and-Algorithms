/*
    Count number of substrings with exactly k distinct characters
    eg: str = "abcbaa", k = 3 => 8
*/

#include <bits/stdc++.h>
using namespace std;

// Count number of substrings with exactly k unique characters
int countkDist(string str, int k)
{
    // size
    int n = str.length();

    // Initialize result
    int res = 0;

    // to store count of characters from 'a' to 'z'
    int count[26];

    // consider all substrings beginning with str[i]
    for (int i = 0; i < n; i++)
    {
        // init var
        int distinctCount = 0;

        // initializing array with 0
        memset(count, 0, sizeof(count));

        // consider all substrings between str[i..j]
        for (int j = i; j < n; j++)
        {
            // new character for this substring ? => increment distinctCount.
            if (count[str[j] - 'a'] == 0)
                distinctCount++;

            // increment count of current character
            count[str[j] - 'a']++;

            // if distinct character count becomes k => increment result.
            if (distinctCount == k)
                res++;
            if (distinctCount > k)
                break;
        }
    }

    // answer
    return res;
}

// Driver Program
int main()
{
    // Given string
    string str = "abcbaa";
    int k = 3;

    // fn call
    cout << "Total substrings with exactly " << k << " distinct characters : "
         << countkDist(str, k) << endl;
}
