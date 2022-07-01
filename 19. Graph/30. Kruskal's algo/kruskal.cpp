/*
    Question: https://rb.gy/wibab3

    Minimum spanning tree is defined for
    Weighted undirected connected graph

    Spanning tree:
        - No cycle
        - Miniumum weight of edges
        - All vertices must be connected

    Kruskal's greedy algo:
        1. Sort edges based on weight (min weight first)
        2. Initialize all vertices as disjoint sets (disconnected)
        3. Traverse through edges array:
            If two edges are not in same set connected connect them
            and merge their sets
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 100001

// Edge structure
struct Edge
{
    int u;
    int v;
    int w;

    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};

// Utility fun
void print(vector<Edge *> &vecEdges)
{
    for (Edge *e : vecEdges)
        cout << e->u << " " << e->v << " " << e->w << '\n';
}

// Disjoint Set Union
int parent[MAX];
int size[MAX];

void make(int v)
{
    parent[v] = v;
    ::size[v] = 1;
}

int find(int v)
{
    if (parent[v] == v)
        return v;
    return parent[v] = find(parent[v]);
}

void unions(int a, int b)
{
    a = find(a);
    b = find(b);

    if (a != b)
    {
        if (::size[a] < ::size[b])
            swap(a, b);
        parent[b] = a;
        ::size[a] += ::size[b];
    }
}

// Driver code
int main()
{
    // n = no. of vertices, m = no. of edges
    int n, m;
    cin >> n >> m;

    // vector of edges
    vector<Edge *> vecEdges;

    // input all edges
    while (m--)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Edge *e = new Edge(u, v, w);
        vecEdges.push_back(e);
    }

    // sort array of vector by edge weight (min first)
    sort(begin(vecEdges), end(vecEdges), [&](Edge *e1, Edge *e2)
         { return e1->w < e2->w; });

    // kruskal's algo
    int sum = 0;

    // init parents
    for (unsigned i = 0; i < vecEdges.size(); i++)
        make(vecEdges[i]->u), make(vecEdges[i]->v);

    // connect edges
    for (unsigned i = 0; i < vecEdges.size(); i++)
    {
        // find representatives of u and v
        int a = find(vecEdges[i]->u);
        int b = find(vecEdges[i]->v);

        // u not connected with v
        if (a != b)
        {
            unions(a, b);
            sum += vecEdges[i]->w;
        }
    }

    // result
    cout << sum << "\n";

    // clear mem
    for (int i = 0; i < vecEdges.size(); i++)
        free(vecEdges[i]);
}

/*

Input:
    4 5
    1 2 7
    1 4 6
    4 2 9
    4 3 8
    2 3 6

Output:
    19
*/