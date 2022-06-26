#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Graph
vector<int> gr[MAX];
bool vis[MAX];

// Helper
void dfs(int src, stack<int> &stk)
{
    vis[src] = 1;

    for (int ch : gr[src])
        if (vis[ch] == 0)
            dfs(ch, stk);

    stk.push(src);
}

// Topological sort using dfs
vector<int> topsort(int numOfVert)
{
    stack<int> stk;
    vector<int> res;

    // traverse cc
    for (int i = 1; i <= numOfVert; i++)
        if (vis[i] == 0)
            dfs(i, stk);

    // store elements in res
    while (!stk.empty())
        res.push_back(stk.top()), stk.pop();

    return res;
}

// Driver code
int main()
{
    /*

    Inputs:
        9 10
        1 2
        3 4
        1 8
        2 9
        2 5
        4 5
        4 8
        5 9
        5 7
        6 7

     */

    // given graph
    int numOfVert, numOfEdge;
    int src, dest;

    cout << "Provide inputs:\n";
    cin >> numOfVert >> numOfEdge;

    // u -> v (directed graph)
    while (numOfEdge--)
    {
        cin >> src >> dest;
        gr[src].push_back(dest);
    }

    // fn call
    vector<int> res;
    res = topsort(numOfVert);

    // result
    cout << "Topological Sorting:\n";
    for (auto val : res)
        cout << val << " ";
}