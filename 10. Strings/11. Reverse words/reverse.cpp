/*
    Reverse given sentence
    eg: hi there => there hi
*/

#include <bits/stdc++.h>
using namespace std;

// Reverse given word using vector
string reverseWord(string str)
{
    // init string stream
    stringstream cin_s(str);
    string word;

    // init vector
    vector<string> reversed;

    // input all string to vector
    while (cin_s >> word)
        reversed.push_back(word);

    // reverse vector
    reverse(reversed.begin(), reversed.end());

    // init answer string
    string ans = "";
    for (auto &val : reversed)
        ans = ans + val + ' ';
    ans.pop_back();
    return ans;
}

/*
    In-place reverse (reverse each word separated by space then reverse whole string)
    (abc def ghi) =>(cba fed ihg) => (ghi def abc)
*/
string reverseWords(string str)
{
    // init start and end
    int start = 0, end = 0;

    // traverse through string
    for (end; end < str.size(); end++)
    {
        // if str[end] = ' ' reverse [start, end] and update start
        if (str[end] == ' ')
        {
            reverse(str.begin() + start, str.begin() + end);
            start = end + 1;
        }
    }
    // revese the last word as it wasn't reversed in loop
    reverse(str.begin() + start, str.begin() + end);

    // reverse whole string
    reverse(str.begin(), str.end());

    // answer
    return str;
}

// Driver code
int main()
{
    // Given string
    string str = "yo guys subscribe to mr beast";

    // fn call;
    cout << reverseWords(str);
}