#include <bits/stdc++.h>
using namespace std;

// split a string separated by space
vector<string> split(string str)
{
    // Used to read from the string as if it were a stream like cin
    stringstream cin_s(str);

    // store individual word
    string word;

    // store all word in str separated by space
    vector<string> result;

    // process each word one by one
    while (cin_s >> word)
        result.push_back(word);

    // return vector result
    return result;
}

// Driver code
int main()
{
    // Given string
    string str = "This is a line and a sentence";

    // fn call
    vector<string> words = split(str);

    // output
    for (auto &val : words)
        cout << val << " ";
}