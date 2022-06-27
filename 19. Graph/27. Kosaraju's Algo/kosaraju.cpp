/*
    Strongly connected component:

    It is a subset C of vertices such that for any 2 vertices
    in C there exist a path between them in the given graph

       SCC1           SCC2
    _ _ _ _ _       _ _ _ _ _
    |  0->1  |     |   5    |     SCC3
    |  ↑  ↓  |     |  ↗  ↘  |      _
    |  3<-2  | --->| 4 <- 6 | --> |7|
    ¯¯¯¯¯¯¯¯¯¯     ¯¯¯¯¯¯¯¯¯¯      ¯
    Total number of strongly connected components = 3

    - SCC is only valid for Dircted Graph
    - Transpose graph => each edge reversed in original graph
    - After transpose, num of SCC doesn't change
    - Condensation graph => each SCC acts as vertex
    - SCC1 -> SCC2 -> SCC3 is condensation graph of above
    - Condensation graph doesn't contain any cycle
    - A DAG has at least 1 node with indegree 0

*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

/* Kosaraju's algo to find scc */

// Topological sort
void topSort(
    int src,
    stack<int> &stk,
    vector<bool> &vis,
    vector<int> gr[])
{
    vis[src] = 1;

    for (int ch : gr[src])
        if (vis[ch] == 0)
            topSort(ch, stk, vis, gr);

    stk.push(src);
}

// Dfs
void dfs(
    int src,
    vector<bool> &vis,
    vector<int> gr[])
{
    vis[src] = 1;

    for (int ch : gr[src])
        if (vis[ch] == 0)
            dfs(ch, vis, gr);
}

// Driver code
int main()
{
    /*
        _ _ _ _ _       _ _ _ _ _
        |  0->1  |     |   5    |     SCC3
        |  ↑  ↓  |     |  ↗  ↘  |      _
        |  3<-2  | --->| 4 <- 6 | --> |7|
        ¯¯¯¯¯¯¯¯¯¯     ¯¯¯¯¯¯¯¯¯¯      ¯
    */

    vector<vector<int>> edges =
        {{0, 1},
         {1, 2},
         {2, 3},
         {3, 0},
         {2, 4},
         {4, 5},
         {5, 6},
         {6, 4},
         {6, 7}};
    int num_of_vertices = 8;
    int num_of_edges = 9;

    /* Local variables */
    vector<int> gr[num_of_vertices];
    vector<int> tr[num_of_vertices];
    vector<bool> vis(num_of_vertices, 0);
    stack<int> stk;

    // build graph
    for (int i = 0; i < num_of_edges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        gr[u].push_back(v);
    }

    // step 1: find top sort order
    for (int i = 0; i < num_of_vertices; i++)
        if (vis[i] == 0)
            topSort(i, stk, vis, gr);

    // step 2: transpose
    for (int i = 0; i < num_of_edges; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];

        tr[v].push_back(u);
    }

    // step 3: run dfs for scc count
    fill(vis.begin(), vis.end(), 0);
    int strongly_cc = 0;

    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();

        if (vis[cur] == 0)
        {
            dfs(cur, vis, tr);
            strongly_cc++;
        }
    }

    cout << strongly_cc;
}