/*
    This solution is correct but gives TLE in leetcode, AC in codingninjas
    https://youtu.be/ZkjQ4avxze4?t=1944
    https://leetcode.com/problems/word-ladder/
    https://www.codingninjas.com/codestudio/problems/word-ladder_1102319
*/
#include <bits/stdc++.h>
using namespace std;

// check if two words differ by 1 char
bool isValid(string w1, string w2)
{
    int cnt = 0;
    for (int i = 0; i < w1.size(); i++)
    {
        if (w1[i] != w2[i])
            cnt++;
        if (cnt > 1)
            return false;
    }

    return cnt == 1;
}

// Given function
int ladderLength(string begin, string end, vector<string> &dict)
{
    // check if word exists
    bool flag = false;
    for (int i = 0; i < dict.size(); i++)
        if (dict[i] == end)
            flag = true;

    // if not return ladder length of 0
    if (!flag)
        return 0;

    // init graph
    map<string, set<string>> gr;
    map<string, bool> vis;

    // build graph
    dict.push_back(begin);
    dict.push_back(end);

    for (int i = 0; i < dict.size(); i++)
    {
        for (int j = i + 1; j < dict.size(); j++)
        {
            if (isValid(dict[i], dict[j]))
            {
                gr[dict[i]].insert(dict[j]);
                gr[dict[j]].insert(dict[i]);
            }
        }
    }

    // print graph
    // for (auto pair : gr)
    // {
    //     cout << pair.ff << ": ";
    //     for (auto str : pair.ss)
    //         cout << str << " ";
    //     cout << endl;
    // }

    // create qu for traversal
    queue<pair<string, int>> qu;
    qu.push({begin, 1});
    vis[begin] = 1;

    // bfs
    while (!qu.empty())
    {
        string curr = qu.front().first;
        int dist = qu.front().second;
        qu.pop();

        if (curr == end)
            return dist;

        for (auto ch : gr[curr])
        {
            if (vis[ch] == 0)
            {
                vis[ch] = 1;
                qu.push({ch, dist + 1});
            }
        }
    }

    return 0;
}

// Driver code
int main()
{
    string begin = "goa", end = "pro";
    vector<string> dict = {"poa", "pro", "bro", "say", "pra"};

    cout << "len = " << ladderLength(begin, end, dict);
}
