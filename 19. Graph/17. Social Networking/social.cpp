/*
    Link:
    https://www.youtube.com/watch?v=8VAOCWmLZcU&list=PL5DyztRVgtRVLwNWS7Rpp4qzVVHJalt22&index=21
*/
#include <bits/stdc++.h>
using namespace std;

// fast io
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

// keywords
#define ll long long int
#define pb push_back
#define ff first
#define ss second
#define endl '\n'
#define err exit(0)

// constants
#define inf 1'000'000'000
#define pi 3.1415926535897932384626
#define mod 1'000'000'007

// containers
#define pii pair<int, int>
#define pll pair<ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define vs vector<string>
#define vvs vector<vector<string>>
#define all(x) x.begin(), x.end()

// loops
#define fr(i, n) for (ll i = 0; i < n; i++)
#define rp(i, n) for (ll i = 1; i <= n; i++)

// print
#define pr cout <<
#define deb(x) pr #x << " = " << x << endl;
template <typename T> void prv(vector<T> v) {fr(i, v.size()) pr v[i] << " "; pr endl; }
template <typename T> void prvv(vector<T> v) {fr(i, v.size()) {fr(j, v[i].size()) pr v[i][j] << " "; pr endl;}}

// ============ Question ============ //
#define MAX 10001
vi gr[MAX];
int vis[MAX], dis[MAX];

// bfs
void bfs(int src)
{
    queue<int>qu;
    qu.push(src);
    vis[src] = 1;
    dis[src] = 0;

    while(!qu.empty())
    {
        int curr = qu.front();
        qu.pop();

        for(int ch: gr[curr])
        {
            if(vis[ch] == 0)
            {
                vis[ch] = 1;
                dis[ch] = dis[curr] + 1;
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

    int tc, v, e, a, b; cin >> tc;

    while(tc--)
    {
        // ip no of vert, no of edge
        cin >> v >> e;

        // clear prev ip
        fr(i, v) gr[i].clear(), vis[i] = 0;

        // ip each edge and build graph
        fr(i, e) cin >> a >> b, gr[a].pb(b), gr[b].pb(a);

        // 
        vvi disar; vi temp;
        rp(i, v) 
        {
            // clear all 
            rp(i, v) dis[i] = 0, vis[i] = 0; temp.clear();

            // bfs and fill dis each time
            bfs(i);

            // copy dis to temp
            rp(i, v) temp.pb(dis[i]);

            // create disarr
            disar.pb(temp);
        }

        // prvv(disar);

        // input node and distance to be printed
        int cnt = 0, node, dist; cin >> node >> dist;

        // print node and dist
        for(int val: disar[node - 1])
        {
            cnt++;
            if(val == dist) pr cnt << " ";
        }
    }
}
// ============ Question ============ //