/*
    https://www.spoj.com/problems/PT07Y/

    To ensure a graph is a tree:
        1. There should be only one connected component
        2. Total number of edges = no. of vertices - 1
*/

#include <bits/stdc++.h>
using namespace std;

vector<bool> vis(10001, false);
vector<int> adj[10001];

// normal dfs
void dfs(int s)
{
    vis[s] = true;
    for (auto c : adj[s])
        if (vis[c] == false)
            dfs(c);
}

// Driver code
int main()
{
    // input total vertex, total edges
    int n, m;
    cin >> n >> m;

    // input graph
    for (int i = 1; i <= m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // count connected components
    int cc = 0;
    for (int i = 1; i <= n; i++)
        if (vis[i] == false)
            dfs(i), cc++;

    // if connected components = 1, total edge = n - 1
    if (cc == 1 && m == n - 1)
        cout << "YES";
    else
        cout << "NO";
}