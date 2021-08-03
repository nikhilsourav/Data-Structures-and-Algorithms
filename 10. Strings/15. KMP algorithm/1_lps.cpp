// Construct longest proper-prefix and suffix array
#include <bits/stdc++.h>
using namespace std;

// build LPS array
void fillLPS(string str, int *LPS)
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

// Driver code
int main()
{
    // Given string
    string str = "abacabad"; // 0 0 1 0 1 2 3 0

    // lps array
    int LPS[str.size()];

    // fn call
    fillLPS(str, LPS);

    // output LPS
    for (auto &x : LPS)
        cout << x << " ";
}

/*
    NOTES:

    ============ suffix and proper prefix =============

    str = "abcd"
     proper prefix : "", "a", "ab", "abc"
     suffix        : "", "d", "cd", "bcd", "abcd"

    ============ constructing LPS array =============

    str = "ababc"

    "a"                                         {0, , , , }
        pf: ""
        sf: "" "a"

    "ab"                                        {0, 0, , , }
        pf: "" "a"
        sf: "" "b" "ab"

    "aba"                                       {0, 0, 1, , }
        pf: "" "a" "ab"
        sf: "" "a" "ba" "aba"

    "abab"                                      {0, 0, 1, 2, }
        pf: "" "a" "ab" "aba"
        sf: "" "b" "ab" "bab" "abab"

    "ababc"                                     {0, 0, 1, 2, 0}
        pf: "" "a" "ab" "aba" "abab"
        sf: "" "c" "bc" "abc" "babc" "ababc"   

    ============ key points =============

    * first entry in LPS array is always 0, as for string of length 1
      we can't have proper prefix more than 0

    * for second entry if two characters are equal then 1 otherwise 0
*/