#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Global vars
vector<int> gr[MAX];
bool vis[MAX];
int dist[MAX];

// BFS
void bfs(int src)
{
    vis[src] = 1;
    dist[src] = 0;
 
    queue<int> qu;
    qu.push(src);
 
    while (!qu.empty())
    {
        int curr = qu.front();
        qu.pop();
 
        for (int ch : gr[curr])
        {
            if (vis[ch] == 0)
            {
                vis[ch] = 1;
                dist[ch] = dist[curr] + 1;
                qu.push(ch);
            }
        }
    }
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
    bfs(1);

    for (int i = 1; i <= 5; i++)
        cout << dist[i] << " ";
}