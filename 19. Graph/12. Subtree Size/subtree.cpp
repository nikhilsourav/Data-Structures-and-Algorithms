#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Graph
vector<int> gr[MAX];
bool vis[MAX];
int subsize[MAX];

// DFS
int dfs(int src)
{
    vis[src] = true;
    int currsize = 1;

    for (int ch : gr[src])
        if (vis[ch] == false)
            currsize += dfs(ch);

    subsize[src] = currsize;
    return currsize;
}

// Driver code
int main()
{
    /*

         1
        /
       2
      / \
     3   4
          \
           5

    1 [2]
    2 [1,3,4]
    3 [2]
    4 [2,5]
    5 [4]

    */

    // build graph
    gr[1].push_back(2);

    gr[2].push_back(1);
    gr[2].push_back(3);
    gr[2].push_back(4);

    gr[3].push_back(2);

    gr[4].push_back(2);
    gr[4].push_back(5);

    gr[5].push_back(4);

    int n = 5;
    cout << dfs(1);
}