/*
    Group anagrams together
    https://leetcode.com/problems/group-anagrams/
*/

#include <bits/stdc++.h>
using namespace std;

// Group anagrams
vector<vector<string>> Anagrams(vector<string> &strs)
{
    // anwser vector
    vector<vector<string>> ans;

    // size of given vector
    int n = strs.size();

    // if given vector is empty
    if (n == 0)
        return ans;

    // create map
    unordered_map<string, vector<string>> m;

    // sort each string
    for (auto i : strs)
    {
        string s = i;
        sort(s.begin(), s.end());
        m[s].push_back(i);
    }

    // push in map
    for (auto i : m)
        ans.push_back(i.second);

    // answer
    return ans;
}

// Driver code
int main()
{
    // Given string
    vector<string> words = {"act", "god", "cat", "dog", "tac"};

    // Store ans
    vector<vector<string>> ans = Anagrams(words);

    // Print answer
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}