/*
    Can't check whether my soln is correct or not

    qus: https://assessment.hackerearth.com/challenges/college/nits-local-10/algorithm/84888e824aa04fc793c3beefca02b5a7/

    There are N countries {1,2,3,4....N} and N-1 roads(i.e depicting a tree)
    Bishu lives in the Country 1 so this can be considered as the root of the tree.
    Now there are Q girls who lives in various countries (not equal to 1) .
    All of them want to propose Bishu.But Bishu has some condition.
    He will accept the proposal of the girl who lives at minimum distance from his country.
    Now the distance between two countries is the number of roads between them.
    If two or more girls are at the same minimum distance then he will accept the proposal of
    the girl who lives in a country with minimum id.
    No two girls are at same country.
    Input: First line consists of N,i.e number of countries Next N-1 lines follow the type
    u v which denotes there is a road between u and v. Next line consists of Q Next Q lines
    consists of x where the girls live.
    Output: Print the id of the country of the girl who will be accepted.

    contraints: 2<=N<=1000 1<=u,v<=N 1<=Q<=(N-1)

    Input:

    6
    1 2
    1 3
    1 4
    2 5
    2 6
    4
    5
    6
    3
    4

    Output:

    3

*/
#include <bits/stdc++.h>
using namespace std;

// Single source shortest path
void sssp(
    int s,
    vector<bool> &visited,
    vector<int> adj[],
    vector<int> &distArr,
    int dist)
{
    visited[s] = true;
    distArr[s] = dist;

    for (auto c : adj[s])
        if (visited[c] == false)
            sssp(c, visited, adj, distArr, dist + 1);

    dist--;
}

// Driver code
int main()
{
    // Input size and init adj
    int n;
    cin >> n;
    vector<int> adj[n + 1];

    // input connection
    int size = n;
    n -= 1;
    while (n--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // input where girls live
    unordered_set<int> girlsLive;
    int x;
    cin >> x;
    while (x--)
    {
        int w;
        cin >> w;
        girlsLive.insert(w);
    }

    // fill dist array
    vector<bool> visited(size + 1, false);
    vector<int> distArr(size + 1, 0);
    sssp(1, visited, adj, distArr, 0);

    // find min in distArr
    int minim = INT_MAX;
    for (auto val : distArr)
        if (val != 0 and val < minim)
            minim = val;

    // search distArr and find
    for (int i = 1; i <= size; i++)
    {
        if (distArr[i] == minim && girlsLive.find(i) != girlsLive.end())
        {
            cout << i;
            break;
        }
    }

    return 0;
}