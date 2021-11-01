/*
    Count total number of words in string
    eg: str = "Geeks for Geeks" => Geeks: 2, for: 1
    https://www.geeksforgeeks.org/stringstream-c-applications/
*/

#include <bits/stdc++.h>
using namespace std;

// Count
void count(string str)
{
    // init stringstream
    stringstream cin_s(str);

    // to store each word
    string word;

    // init count var
    int count = 0;

    // read words
    while (cin_s >> word)
        count++;

    // print result
    cout << "Total words in str is: " << count << "\n";
}

// Print frequency of each word in a string
void printFreq(string str)
{
    // init map
    map<string, int> freqMap;

    // init string stream used for breaking word
    stringstream ss(str);

    // to store individual word
    string word;

    // extract each word and increment frequency
    while (ss >> word)
        freqMap[word]++;

    // output
    for (auto &val : freqMap)
        cout << val.first << " " << val.second << "\n";
}

// Driver code
int main()
{
    // Given string
    string str = "Geeks For Geeks Ide";

    // fn call
    printFreq(str);
    count(str);
}
