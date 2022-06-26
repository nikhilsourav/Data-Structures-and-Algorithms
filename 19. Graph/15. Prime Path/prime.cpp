/*
    Question: https://www.spoj.com/problems/PPATH/
*/
#include <bits/stdc++.h>
using namespace std;

// fast io
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

// keywords
#define pb push_back
#define endl '\n'

// constants
#define ERR exit(0)

// containers
#define vi vector<int>

// loops
#define fr(i, n) for (int i = 0; i < n; i++)
#define rep(i, n) for (int i = 1; i <= n; i++)

// print
#define pr cout <<
#define deb(x) pr #x << " = " << x << endl;

// ============ Question ============ //
#define MAX 10001
vector<int>gr[MAX];
int vis[MAX];
int dist[MAX];

// Check if two numbers differ only by one digit
bool is_valid(int x, int y)
{
    int cnt = 0;

    while(x)
    {
        if(x % 10 != y % 10) cnt++;
        x /= 10, y /= 10;
    }

    return cnt == 1;
}

// Check if a number is prime
bool is_prime(int n)
{
    for(int i = 2; i * i <= n; i++) if(n % i == 0) return false; return true;
}

// Build graph out of given nodes
void build_graph()
{
    vi v;

    for(int i = 1000; i <= 9999; i++)
        if(is_prime(i)) v.pb(i);

    fr(i, v.size())
    fr(j, v.size())
        if(i != j && is_valid(v[i], v[j])) gr[v[i]].pb(v[j]), gr[v[j]].pb(v[i]);
}

// Run bfs to find shortest path
void bfs(int src)
{
    queue<int>qu;
    qu.push(src);
    vis[src] = 1;
    dist[src] = 0;

    while(!qu.empty())
    {
        int cur = qu.front();
        qu.pop();

        for(int ch: gr[cur])
        {
            if(vis[ch] == 0)
            {
                vis[ch] = 1;
                dist[ch] = dist[cur] + 1;
                qu.push(ch);
            }
        }
    }
}

// Driver code
int main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("_i.txt", "r", stdin);
    freopen("_o.txt", "w", stdout);
#endif

    int src, dest, tc; cin >> tc;

    while(tc--)
    {
        cin >> src >> dest;

        fr(i, MAX) gr[i].clear(), dist[i] = -1, vis[i] = 0;

        build_graph();

        bfs(src);

        if(dist[dest] == -1)
            pr "Impossible" << endl;
        else
            pr dist[dest] << endl;
    }
}