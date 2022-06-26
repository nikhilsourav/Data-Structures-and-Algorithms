/*
    https://leetcode.com/problems/critical-connections-in-a-network/
*/

#include <bits/stdc++.h>
using namespace std;

int timer;

// Find bridges
void dfs(
    int src,
    int par,
    vector<vector<int>> &res,
    unordered_map<int, vector<int>> &gr,
    unordered_map<int, bool> &vis,
    vector<int> &in,
    vector<int> &low)
{
    vis[src] = 1;
    in[src] = low[src] = timer;
    timer++;

    for (int ch : gr[src])
    {
        if (ch == par)
            continue;

        if (vis[ch] == 1)
        {
            low[src] = min(low[src], in[ch]);
        }
        else
        {
            dfs(ch, src, res, gr, vis, in, low);

            if (low[ch] > in[src])
                res.push_back({src, ch});

            low[src] = min(low[src], low[ch]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    // data structures
    int parent = -1;
    vector<vector<int>> res;
    unordered_map<int, vector<int>> gr;
    unordered_map<int, bool> vis;
    vector<int> in(n, -1);
    vector<int> low(n, -1);

    // construct graph
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];

        gr[u].push_back(v);
        gr[v].push_back(u);
    }

    // call dfs
    timer = 0;
    dfs(0, -1, res, gr, vis, in, low);

    return res;
}

// Driver code
int main()
{
    vector<vector<int>> connections =
        {
            {0, 1},
            {1, 2},
            {2, 0},
            {1, 3},
            {0, 1},
        };

    int n = 4;

    vector<vector<int>> res = criticalConnections(n, connections);

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i][0] << " - " << res[i][1] << " is a critical failure\n";
    }
}