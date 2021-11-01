/*
    Split a string separated by space and store it in vector
    eg: str = "This is a word", vect = ["This", "is", "a", "word"]
*/

#include <bits/stdc++.h>
using namespace std;

// Split and store
vector<string> split(string str)
{
    // stringstream is used to read from the string as if it were a stream like cin
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

    // Output
    for (auto &val : words)
        cout << val << " ";
}