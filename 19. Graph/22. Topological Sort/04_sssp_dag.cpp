// Given a DAG find shortest path from single source
#include <bits/stdc++.h>
using namespace std;

// Get order of topological sorting
void topSortOrder(
    int src,
    stack<int> &stk,
    vector<int> &vis,
    vector<pair<int, int>> gr[])
{
    vis[src] = 1;
    for (auto ch : gr[src])
        if (vis[ch.first] == 0)
            topSortOrder(ch.first, stk, vis, gr);

    stk.push(src);
}

// Single source shortest path in dag
void shortestPath(
    int src,
    stack<int> &stk,
    vector<int> &dist,
    vector<pair<int, int>> gr[])
{
    dist[src] = 0;

    while (!stk.empty())
    {
        int cur = stk.top();
        stk.pop();

        if (dist[cur] != INT_MAX)
            for (auto ch : gr[cur])
                if (dist[ch.first] > dist[cur] + ch.second)
                    dist[ch.first] = dist[cur] + ch.second;
    }
}

// Driver code
int main()
{
    // local variables
    int numVert = 6;
    vector<pair<int, int>> gr[numVert];
    vector<int> vis(numVert, 0); // for topological sort
    vector<int> dist(numVert, INT_MAX);
    stack<int> stk;
    int src = 0;

    /*
        SrcVertex: {destVertex, edgeWeight}
        0: {1,2} {4,1}
        1: {2,3}
        2: {3,6}
        3:
        4: {2,2} {5,4}
        5: {3,1}
    */
    gr[0].push_back({1, 2});
    gr[0].push_back({4, 1});
    gr[1].push_back({2, 3});
    gr[2].push_back({3, 6});
    gr[4].push_back({2, 2});
    gr[4].push_back({5, 4});
    gr[5].push_back({3, 1});

    // find topsort order and then sssp
    topSortOrder(src, stk, vis, gr);
    shortestPath(src, stk, dist, gr);

    // print result
    cout << "Distance of: \n";
    for (int i = 0; i < numVert; i++)
        cout << src << " - " << i << " is: " << dist[i] << "\n";
}