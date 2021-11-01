/*
    Check if pattern or it's permutation is present in given text
    eg: text = "geeksforgeeks", pattern = "frog" => true
*/

#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

// Check if two array are equal
bool areSame(int countTxt[], int countPat[])
{
    for (int i = 0; i < CHAR; i++)
        if (countTxt[i] != countPat[i])
            return false;

    return true;
}

// Time: O(n*CHAR)
bool isPresent(string &txt, string &pat)
{
    // init vars
    int countTxt[CHAR] = {0}, countPat[CHAR] = {0};

    // count frequency of each char in txt and pat upto pat.size()
    for (int i = 0; i < pat.size(); i++)
    {
        countTxt[txt[i]]++;
        countPat[pat[i]]++;
    }

    // count  and check frequency for subsequent window
    for (int i = pat.size(); i < txt.size(); i++)
    {
        // if both array equal
        if (areSame(countTxt, countPat))
            return true;

        // slide window
        countTxt[txt[i]]++;
        countTxt[txt[i - pat.size()]]--;
    }

    // if not found
    return false;
}

// Driver code
int main()
{
    // Given string
    string txt = "geeksforgeeks", pat = "gofr";

    // fn call
    cout << boolalpha << isPresent(txt, pat);
}