#include <bits/stdc++.h>
using namespace std;

/*
    Questin: https://bit.ly/3axYOSF

    - Index of array elements act as vertex
    - Index start from 0

      [2]   [3]
    0-----1-----2
 [6]|    /|    /
    |[8]/ |[7]/
    |  /  |  /
    | /[5]| /
    |/    |/
    3     4

    Given undirected graph with weights find mst

    index:  0   1    2    3    4
    weight [0, inf, inf, inf, inf]
    parent [-1, -1,  -1,  -1,  -1]
    mst    [F,   F,   F,   F,   F]

    step 1: find minimum value in weight call it 'minWeight' and the
            vertex (index) corresponding to minWeight, call it minVertex
    step 2: Mark mst[minVertex] = T
    step 3: Find all adj of 'minVertex' and update their weight and parent

*/

#include <bits/stdc++.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // 1 - based indexing
    unordered_map<int, vector<pair<int, int>>> gr;

    // build graph
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;

        gr[u].push_back({v, w});
        gr[v].push_back({u, w});
    }

    // prim's algo
    vector<int> weight(n + 1, INT_MAX);
    vector<bool> mst(n + 1, false);
    vector<int> parent(n + 1, -1);

    // first node
    weight[1] = 0;
    parent[1] = -1;

    for (int i = 1; i < n; i++)
    {
        int minWeight = INT_MAX;
        int minVertex;

        // step 1: find minimum value in weight call it 'minWeight'
        // and the vertex (index) corresponding to minWeight, call it minVertex
        for (int v = 1; v <= n; v++)
            if (mst[v] == false && weight[v] < minWeight)
                minWeight = weight[v], minVertex = v;

        // step 2: Mark mst[minVertex] = T
        mst[minVertex] = true;

        // step 3: Find all adj of 'minVertex' and update their weight and parent
        for (auto ch : gr[minVertex])
        {
            int v = ch.first;
            int w = ch.second;

            if (mst[v] == false && w < weight[v])
                parent[v] = minVertex, weight[v] = w;
        }
    }

    // return result
    vector<pair<pair<int, int>, int>> res;

    for (int i = 2; i <= n; i++)
        res.push_back({{parent[i], i}, weight[i]});

    return res;
}

// Driver code
int main()
{
    vector<pair<pair<int, int>, int>> graph =
        {
            {{1, 2}, 2},
            {{1, 4}, 6},
            {{2, 1}, 2},
            {{2, 3}, 3},
            {{2, 4}, 8},
            {{2, 5}, 5},
            {{3, 2}, 3},
            {{3, 5}, 7},
            {{4, 1}, 6},
            {{4, 2}, 8},
            {{4, 5}, 9},
            {{5, 2}, 5},
            {{5, 3}, 7},
            {{5, 4}, 9},
        };

    int num_of_vertices = 5, num_of_edges = 14;

    /*
    Output:
        1 2 2
        1 4 6
        2 3 3
        2 5 5
    */

    vector<pair<pair<int, int>, int>> res =
        calculatePrimsMST(num_of_vertices, num_of_edges, graph);

    for (auto val : res)
        cout << val.first.first << " " << val.first.second << " " << val.second << endl;
}