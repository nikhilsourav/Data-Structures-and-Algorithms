/*
    Check whether given string is pangram (containing all characters of english alphabet)
    eg: str = "The quick brown fox jumps over the lazy dog" => true
*/

#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

// Pangram without using set
bool checkPangram(string &str)
{
    // initialize an array of 256 chars with all elements as 0
    int mark[CHAR] = {};

    // init index and size
    int index = 0, n = str.size();

    // logic
    for (int i = 0; i < n; i++)
    {
        // increment mark for each uppercase character
        if (str[i] >= 65 && str[i] <= 90)
        {
            index = str[i] - 65;
            mark[index]++;
        }
        // increment mark for each lowercase character
        else if (str[i] >= 97 && str[i] <= 122)
        {
            index = str[i] - 97;
            mark[index]++;
        }
    }

    // if any mark value is 0 that means a char is missing from a-z
    for (int i = 0; i < 26; i++)
        if (mark[i] == 0)
            return false;

    // if pangram
    return true;
}

// Driver code
int main()
{
    // Given string
    string s = "Bawds jog, flick quartz, vex nymph";

    // fn call
    cout << boolalpha << checkPangram(s);
}