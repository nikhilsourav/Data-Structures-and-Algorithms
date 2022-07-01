// Check if cycle exist in directed graph using topological sort
#include <bits/stdc++.h>
using namespace std;

// Fn to check whether cycle exist
bool hasCycle(vector<int> adj[], int numVert)
{
    vector<int> indegree(numVert, 0);
    queue<int> qu;

    // count indegree
    for (int i = 0; i < numVert; i++)
        for (int ch : adj[i])
            indegree[ch]++;

    // push node with indegree 0
    for (int i = 0; i < indegree.size(); i++)
        if (indegree[i] == 0)
            qu.push(i);

    // at some point indegree of all node is not 0
    // thus count can never become equal to numvert
    int cnt = 0;
    while (!qu.empty())
    {
        int cur = qu.front();
        qu.pop();

        for (int ch : adj[cur])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
                qu.push(ch);
        }

        cnt++;
    }

    // if all nodes are processed i.e. cnt == numVert => cycle
    return cnt != numVert;
}

// Function to add edge
void addEdge(vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
}

// Driver code
int main()
{
    // lcoal vars
    int numVert = 6;
    vector<int> adj[numVert];

    // build graph
    addEdge(adj, 0, 1);
    addEdge(adj, 2, 1);
    addEdge(adj, 2, 3);
    addEdge(adj, 3, 4);
    addEdge(adj, 4, 5);
    addEdge(adj, 5, 3);

    // fn call
    hasCycle(adj, numVert) == 1 ? cout << "Cycle" : cout << "No Cycle";
}
