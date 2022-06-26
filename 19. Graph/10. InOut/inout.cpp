#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Global vars
vector<int> gr[MAX];
bool vis[MAX];
int in[MAX];
int out[MAX];
int timer = 1;

// DFS
void dfs(int src)
{
    vis[src] = true;
    in[src] = timer++;

    for (int ch : gr[src])
        if (vis[ch] == false)
            dfs(ch);

    out[src] = timer++;
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

    // fn call
    dfs(1);
    for (int i = 1; i <= 5; i++)
        cout << i << ": " << in[i] << " " << out[i] << endl;
}