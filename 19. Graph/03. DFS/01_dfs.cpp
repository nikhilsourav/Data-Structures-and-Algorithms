/*
    https://youtu.be/9_ftWKch6vI?t=1341
*/
#include <bits/stdc++.h>
using namespace std;

// Global vars
unordered_map<int, bool> visited;
unordered_map<int, vector<int>> graph;

// DFS
void dfs(int vertex)
{
    /*
        Take action on the vertex
        after entering the vertex
    */
    visited[vertex] = true;
    cout << vertex << " ";

    for (int child: graph[vertex])
    {
        /*
            Take action on the child
            before entering the child
        */
        if (visited[child] == 0)
        {
            dfs(child);
            /*
                Take action on the child
                after entering the child
            */
        }
    }
    /*
        Take action on vertex
        before exiting the vertex
    */
}

// Driver code
int main()
{
    /*

        10
       /
      20
     / \
    30  40
       / \
      50   60

    10: 20
    20: 10->30->40
    30: 20
    40: 20->50->60
    50: 40
    60: 40

    */

    // build graph
    graph[10].push_back(20);

    graph[20].push_back(10);
    graph[20].push_back(30);
    graph[20].push_back(40);

    graph[30].push_back(20);

    graph[40].push_back(20);
    graph[40].push_back(50);
    graph[40].push_back(60);

    graph[50].push_back(40);
    graph[60].push_back(40);

    // fn call
    dfs(10);
}