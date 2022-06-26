#include <bits/stdc++.h>
using namespace std;

// DFS
void dfs(
    int src,
    int dest,
    vector<int> &temp,
    vector<vector<int>> &res,
    vector<vector<int>> &gr)
{
    /*
        Take action on the vertex
        after entering the vertex
    */
    temp.push_back(src);
    if (src == dest)
        res.push_back(temp);

    for (int ch : gr[src])
    {
        /*
            Take action on the child
            before entering the child
        */
        dfs(ch, dest, temp, res, gr);
        /*
            Take action on the child
            after entering the child
        */
    }

    temp.pop_back();
    /*
        Take action on vertex
        before exiting the vertex
    */
}

// Given fn
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    // source is always 0, destination is always g.size() - 1
    int src = 0, dest = graph.size() - 1;

    // init vectors
    vector<vector<int>> res;
    vector<int> temp;

    // call dfs
    dfs(0, dest, temp, res, graph);

    // return res
    return res;
}

// Driver code
int main()
{
    /*
        0 -> 1
        |    |
        2 -> 3

        0 [1, 2]
        1 [3]
        2 [3]
        3 []
    */
    vector<vector<int>> gr = {{1, 2}, {3}, {3}, {}};
    gr = allPathsSourceTarget(gr);

    // output
    for (int i = 0; i < gr.size(); i++)
    {
        for (int j = 0; j < gr[i].size(); j++)
            cout << gr[i][j] << " ";
        cout << endl;
    }
}