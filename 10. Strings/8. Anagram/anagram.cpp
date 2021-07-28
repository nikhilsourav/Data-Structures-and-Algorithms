#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

// check anagram (permutation of each other) in lowercase alphabets
bool checkAnagram(string s1, string s2)
{
    // initial check
    if (s1.size() != s2.size())
        return false;

    // initialize char array of size 256
    int count[CHAR] = {0};

    // increment s1[i]'s count decrement s2[i]'s count:
    for (int i = 0; i < s1.size(); i++)
    {
        count[s1[i]]++;
        count[s2[i]]--;
    }

    // check
    for (int i = 0; i < CHAR; i++)
        if (count[i] != 0)
            return false;

    // answer
    return true;
}

// Driver code
int main()
{
    // Given string
    string s1 = "listen", s2 = "silent";

    // fn call
    cout << boolalpha << checkAnagram(s1, s2);
}