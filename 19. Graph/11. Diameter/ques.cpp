/*
    Question: https://www.spoj.com/problems/PT07Z/
*/
#include <bits/stdc++.h>
using namespace std;

// fast io
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);

// vectors
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define pb push_back
#define all(x) x.begin(), x.end()

// loops
#define fr(i, n) for (int i = 1; i <= n; i++)
#define _fr(n, i) for (int i = n - 1; i >= 0; i--)

// constants
#define inf INT_MAX
#define _inf INT_MIN
#define in long long int
#define mod 1000000007
#define err exit(0)

// print
#define p cout <<
void pvi(vi v) { in i = 0; fr(i, v.size()) p v[i] << " "; }
void pvvi(vvi v) { in i = 0; fr(i, v.size()) { in j = 0; fr(j, v[i].size()) p v[i][j] << " "; p endl; } }
void pvs(vs v) { in i = 0; fr(i, v.size()) p v[i] << " "; }
void pvvs(vvs v) { in i = 0; fr(i, v.size()) { in j = 0; fr(j, v[i].size()) p v[i][j] << " "; p endl; } }

// math
in exp(in x, in y){in r = 1; while (y > 0){if (y & 1) r = (r * x) % mod; x = (x * x) % mod; y = y >> 1;} return r;}

// Question
#define MAX 1000001
vi gr[MAX];
bool vis[MAX];
int maxDist;
int maxNode;

// dfs
void dfs(int src, int dis)
{
    vis[src] = 1;

    if(dis > maxDist) maxDist = dis, maxNode = src;

    for(int ch: gr[src])
        if(vis[ch] == false)
            dfs(ch, dis + 1);
}

// Driver code
int main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    // local variables
    int n, u, v;

    cin >> n;

    // input edges
    fr(i, n - 1) cin >> u >> v, gr[u].pb(v), gr[v].pb(u);

    // dfs to find max distance from a random node
    maxDist = -1;
    dfs(1, 0);

    // reset visited array
    fr(i, n) vis[i] = 0;

    // dfs to find diameter of tree
    maxDist = -1;
    dfs(maxNode, 0);

    // print result
    cout << maxDist << "\n";
}