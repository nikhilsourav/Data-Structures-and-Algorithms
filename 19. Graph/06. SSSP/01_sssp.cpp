#include <bits/stdc++.h>
using namespace std;

// Single source shortest path on tree not graph
void dfs(
    int source,
    vector<bool> &visited,
    vector<int> adj[],
    vector<int> &distArr,
    int dist)
{
    visited[source] = true;
    distArr[source] = dist;

    for (auto child : adj[source])
        if (visited[child] == false)
            dfs(child, visited, adj, distArr, dist + 1);

    dist--;
}

// Driver
int main()
{
    int numOfVertices = 6;
    vector<int> adj[numOfVertices + 1];
    vector<bool> visited(numOfVertices + 1, false);
    vector<int> distArr(numOfVertices + 1, 0);

    /*
        1
       /
      2
     / \
    3   4
       / \
      5   6

    1: [2]
    2: [1,3,4]
    3: [2]
    4: [2,5,6]
    5: [5]
    6: [4]

    */

    // build graph
    adj[1].push_back(2);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);
    adj[3].push_back(2);
    adj[4].push_back(2);
    adj[4].push_back(5);
    adj[4].push_back(6);
    adj[5].push_back(4);
    adj[6].push_back(4);

    // fn call
    dfs(1, visited, adj, distArr, 0);

    // print distance array
    // index 0 is not used here and distance of 1 from itself is 0
    for (auto val : distArr)
        cout << val << " ";
}