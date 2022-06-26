#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Global vars
vector<bool> vis(MAX, false);
vector<int> gr[MAX];
vector<int> col(MAX);

// Check if graph is bipartite
bool isBipartite(int s, int color)
{
    vis[s] = true;
    col[s] = color;

    for (auto child : gr[s])
    {
        if (vis[child] == false)
        {
            if (isBipartite(child, !color) == false)
                return false;
        }
        else
        {
            if (col[child] == col[s])
                return false;
        }
    }

    return true;
}

// Driver code
int main()
{
    /*
          1
         /
        2
       / \
      3 - 4
            \
             6
    */

    // build graph
    gr[1].push_back(2);
    gr[2].push_back(1);
    gr[2].push_back(3);
    gr[2].push_back(4);
    gr[3].push_back(2);
    gr[3].push_back(4);
    gr[4].push_back(2);
    gr[4].push_back(6);
    gr[6].push_back(4);

    // fn call
    cout << boolalpha << isBipartite(1, 0);
}