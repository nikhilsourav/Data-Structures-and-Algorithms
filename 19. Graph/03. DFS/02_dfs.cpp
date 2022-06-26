#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(int source, vector<int> adj[], vector<bool> &visited)
{
    visited[source] = true;
    cout << source << " ";

    for (auto child : adj[source])
        if (visited[child] == 0)
            dfs(child, adj, visited);
}

// Driver code
int main()
{
    int size = 7;
    vector<int> adj[size + 1];
    vector<bool> visited(size, false);

    /*
        1---3---5
        |   |
        2---4   6---7

        1: [2,3]
        2: [1,4]
        3: [1,4,5]
        4: [2,3]
        5: [3]

        6: [7]
        7: [6]
    */

    // build graph
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(1);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(4);
    adj[3].push_back(5);

    adj[4].push_back(3);
    adj[4].push_back(2);

    adj[5].push_back(3);

    adj[6].push_back(7); // not connected with previous
    adj[7].push_back(6); // not connected with previous

    // traverse all connected components
    for (int i = 1; i < visited.size(); i++)
        if (visited[i] == false)
            dfs(i, adj, visited);
}