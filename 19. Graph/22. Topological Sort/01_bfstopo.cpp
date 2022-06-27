#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Graph
vector<int> gr[MAX];
int indegree[MAX];

// Topological sort kahn's algo
vector<int> topsort(int numOfVert)
{
    queue<int> qu;
    vector<int> res;

    // push indegree[vert] = 0 in qu
    for (int i = 1; i <= numOfVert; i++)
        if (indegree[i] == 0)
            qu.push(i);

    while (!qu.empty())
    {
        int cur = qu.front();
        res.push_back(cur);
        qu.pop();

        // edge removal
        for (int ch : gr[cur])
        {
            indegree[ch]--;
            if (indegree[ch] == 0)
                qu.push(ch);
        }
    }

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
        indegree[dest]++;
    }

    // fn call (cc auto traversed)
    vector<int> res = topsort(numOfVert);

    // result
    cout << "Topological Sorting:\n";
    for (auto val : res)
        cout << val << " ";
}