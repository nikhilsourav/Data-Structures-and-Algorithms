#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Graph
vector<int> gr[MAX];
bool vis[MAX];

// BFS
void bfs(queue<int> &qu)
{
    if (qu.empty())
        return;

    int curr = qu.front();
    cout << curr << " ";
    qu.pop();

    for (int ch : gr[curr])
        if (vis[ch] == 0)
            vis[ch] = 1, qu.push(ch);

    bfs(qu);
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

    queue<int> qu;
    vis[1] = 1;
    qu.push(1);

    bfs(qu);
}