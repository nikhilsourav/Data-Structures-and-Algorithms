/*
    Find cycle in directed graph
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Dfs
bool dfs(
    int src,
    vector<bool> &vis,
    vector<bool> &dfsVis,
    vector<int> gr[])
{
    vis[src] = 1;
    dfsVis[src] = 1;

    for (int ch : gr[src])
    {
        // if not visited vist and call next child
        if (vis[ch] == 0)
        {
            if (dfs(ch, vis, dfsVis, gr) == true)
                return true;
        }
        else
        {
            /*
                if vis[ch] == 1 and dfsVis[ch] == 1
                it means we have already seen this
                node in current dfs call hence cycle
            */
            if (dfsVis[ch] == 1)
                return true;
        }
    }

    dfsVis[src] = 0;

    return false;
}

// Given function
bool hasCycle(int n, vector<int> gr[])
{
    vector<bool> vis(n, 0);
    vector<bool> dfsVis(n, 0);

    for (int i = 0; i < n; i++)
        if (vis[i] == 0)
            if (dfs(i, vis, dfsVis, gr) == true)
                return true;

    return false;
}

// Driver code
int main()
{
    int n = 9;
    vector<int> gr[n + 1];

    /*
        1->2->3->4
          ↗   ↓  ↓
         7    6->5
        ↙ ↖
        8  9

        1: 2
        2: 3
        3: 4,6
        4: 5
        5: 6
        6: 5
        7: 2,8
        8: 9
        9: 7
    */

    // build graph
    gr[1].push_back(2);
    gr[2].push_back(3);
    gr[3].push_back(4);
    gr[3].push_back(6);
    gr[4].push_back(5);
    gr[5].push_back(6);
    gr[6].push_back(5);
    gr[7].push_back(2);
    gr[7].push_back(8);
    gr[8].push_back(9);
    gr[9].push_back(7);

    // fn call
    cout << boolalpha << hasCycle(n, gr);
}