#include <bits/stdc++.h>
using namespace std;

// dfs iterative
void dfs(
    int source,
    vector<bool> &visited,
    vector<int> adj[],
    vector<int> &res)
{
    // Init stack
    stack<int> stk;
    stk.push(source);

    visited[source] = 1;
    res.push_back(source);

    // Logic
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();

        // Check
        for (auto ch : adj[curr])
        {
            if (visited[ch] == false)
            {
                visited[ch] = true;
                res.push_back(ch);
                stk.push(ch);
            }
        }
    }
}

// Driver code
int main()
{
    int numOfVertices = 8;
    vector<int> adj[numOfVertices];
    vector<bool> visited(numOfVertices, false);

    /*
    
       1---3
      /|  /|
     0 | / |
      \|/  |
       2---4

     5-6

     7

     0: [1,2]
     1: [0,2,3]
     2: [0,1,3,4]
     3: [1,4]
     4: [2,3]
     5: [6]
     6: [5]
     7:
    
    */

    // build graph
    adj[0].push_back(1);
    adj[0].push_back(2);

    adj[1].push_back(0);
    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(0);
    adj[2].push_back(1);
    adj[2].push_back(3);
    adj[2].push_back(4);

    adj[3].push_back(1);
    adj[3].push_back(2);
    adj[3].push_back(4);

    adj[4].push_back(2);
    adj[4].push_back(3);

    adj[5].push_back(6);
    adj[6].push_back(5);

    adj[7];

    // fn call
    vector<int> res;
    for (int i = 0; i < numOfVertices; i++)
        if (visited[i] == 0)
            dfs(i, visited, adj, res);

    // print res
    for (auto val : res)
        cout << val << " ";
}