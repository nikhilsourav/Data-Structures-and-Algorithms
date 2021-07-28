/*
    Given a string, the task is to find the first character 
    (whose leftmost appearance is first) that repeats.
*/
#include <bits/stdc++.h>
using namespace std;

// first repeating character
int firstRepeating(string str)
{
    // init map
    unordered_map<char, int> collection;

    // init index
    int index = INT_MAX;

    // logic:
    for (int i = 0; i < str.size(); i++)
    {
        if (collection.find(str[i]) != collection.end())
            index = min(index, collection[str[i]]);
        collection.insert({str[i], i});
    }

    // answer
    if (index == INT_MAX)
        return -1;
    return index;
}

// optimized approach
int firstRepeatingChar(string str)
{
    // init array with false for 256 aasci chars
    bool visited[256] = {0};

    // init result
    int res = -1;

    // logic:
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (visited[str[i]])
            res = i;
        else
            visited[str[i]] = true;
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given string
    string str = "abbcc";

    // fn call
    cout << firstRepeatingChar(str);

    exit(0);

    // init array with false for 256 aasci chars
    bool visited[256] = {};

    // Given string
    char ss[] = {'a', 'b', 'b', 'c', 'c'};

    // init result
    int res = -1;

    // logic:
    for (int i = 4; i >= 0; i--)
    {
        if (visited[ss[i]])
            res = i;
        else
            visited[ss[i]] = true;
    }

    // answer
    cout << res;
}