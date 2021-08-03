// Construct longest proper-prefix and suffix array
#include <bits/stdc++.h>
using namespace std;

// build LPS array
void fillLPS(string &str, int *LPS)
{
    // init size
    int strSize = str.length();

    // first element of LPS is always 0
    LPS[0] = 0;

    // i => traversing and len => keeping track of str length
    int i = 1, len = 0;

    // logic:
    while (i < strSize)
    {
        if (str[i] == str[len])
        {
            len++;
            LPS[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                LPS[i] = 0;
                i++;
            }
            else
            {
                len = LPS[len - 1];
            }
        }
    }
}

// KMP algorithm
void KMP(string &txt, string &pat)
{
    // init size
    int strSize = txt.length(), patSize = pat.length();

    // init LPS array
    int LPS[patSize];

    // construct LPS array
    fillLPS(pat, LPS);

    // init two pointer for traversing
    int i = 0, j = 0;

    // logic:
    while (i < strSize)
    {
        if (pat[j] == txt[i])
        {
            i++;
            j++;
        }

        if (j == patSize)
        {
            cout << "Found pattern at index " << i - j << "\n";
            j = LPS[j - 1];
        }

        else if (i < strSize && pat[j] != txt[i])
        {
            if (j == 0)
                i++;
            else
                j = LPS[j - 1];
        }
    }
}

// Driver code
int main()
{
    // Given string
    string str = "abacabacad", pat = "ca";

    // fn call
    KMP(str, pat);
}
