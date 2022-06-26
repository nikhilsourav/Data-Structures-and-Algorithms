#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(int s, vector<bool> &vis, vector<int> adj[])
{
    vis[s] = true;
    cout << s << " ";

    for (auto child : adj[s])
        if (vis[child] == false)
            dfs(child, vis, adj);
}

// Driver code
int main()
{
    int numOfNodes = 11;
    vector<int> adj[numOfNodes + 1]; // starting index is 1
    vector<bool> vis(numOfNodes + 1, false);

    /*
              1
            / | \
           2  3  4
         / | \    \
        5  6  7    8
                 / | \
                9  10 11

        1: [2,3,4]
        2: [1,5,6,7]
        3: [1]
        4: [1,8]
        5: [2]
        6: [2]
        7: [2]
        8: [4,9,10,11]
        9: [8]
        10: [8]
        11: [8]
    */

    // build graph
    adj[1].push_back(2);
    adj[1].push_back(3);
    adj[1].push_back(4);

    adj[2].push_back(1);
    adj[2].push_back(5);
    adj[2].push_back(6);
    adj[2].push_back(7);

    adj[3].push_back(1);

    adj[4].push_back(1);
    adj[4].push_back(8);

    adj[5].push_back(2);
    adj[6].push_back(2);
    adj[7].push_back(2);

    adj[8].push_back(4);
    adj[8].push_back(9);
    adj[8].push_back(10);
    adj[8].push_back(11);

    adj[9].push_back(8);
    adj[10].push_back(8);
    adj[11].push_back(8);

    // fn call
    dfs(1, vis, adj);
}