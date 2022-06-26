#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Graph
vector<int> gr[MAX];
bool vis[MAX];
int timer;
int in[MAX];  // discovery time
int low[MAX]; // earliest possible time to reach curr node

// DFS
void dfs(int src, int par)
{
    // set in time, low time of current node
    vis[src] = 1;
    in[src] = low[src] = timer;
    timer++;

    for (int ch : gr[src])
    {
        // if child is par
        if (ch == par)
            continue;

        // if child is visited, it's a back edge
        if (vis[ch] == 1)
        {
            /*
                back edge indicates there's another path
                to reach from ch to src hence update low
            */

            low[src] = min(low[src], in[ch]);
        }
        // if child is not visited
        else
        {
            // visit child
            dfs(ch, src);

            /*
                src - ch is a bridge
                this cond signify that this
                is the only way to reach the
                neighbor hence it's a bridge
            */

            if (low[ch] > in[src])
                cout << src << " - " << ch << " is a bridge\n";

            /*
                minimize current node's low
                it is required bcoz it's possible
                that curr node's child has formed
                a back edge with some node which
                means chil'd low has been updated
            */
            low[src] = min(low[src], low[ch]);
        }
    }
}

// Driver code
int main()
{
    /*

    1
     \
      2
     / \
    3---4

    1 [2]
    2 [1,3,4]
    3 [2,4]
    4 [2,3]

    */

    // build graph
    gr[1].push_back(2);

    gr[2].push_back(1);
    gr[2].push_back(3);
    gr[2].push_back(4);

    gr[3].push_back(2);
    gr[3].push_back(4);

    gr[4].push_back(2);
    gr[4].push_back(3);

    dfs(1, -1);
}