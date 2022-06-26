/*
    // incomplete
    Question:  https://urlzs.com/sDvgG
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

// constants
#define INF 1'000'000'000
#define PI 3.1415926535897932384626
#define MOD 1'000'000'007
#define ERR exit(0)

// containers
#define pi pair<int, int>
#define pl pair<ll, ll>
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
#define MAX 100'001
vector<int> gr[MAX];
int vis[MAX], cc[MAX], curr_cc;

// dfs
void dfs(int src)
{
    vis[src] = 1;
    cc[src] = curr_cc;

    for(int ch: gr[src])
        if(vis[ch] == 0)
            dfs(ch);
}

// Driver code
int main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("_i.txt", "r", stdin);
    freopen("_o.txt", "w", stdout);
#endif

    int tc, n, k, a, b; cin >> tc;
    string op; bool flag; vector<pi>ed;

    while(tc--)
    {
        // input no of var & no of rel
        cin >> n >> k;
        curr_cc = 0;

        // clear prev inputs
        rp(i, n) gr[i].clear(), vis[i] = 0;

        // input graph in '=' and edgelist in '!='
        rp(i, k) 
        {
            cin >> a >> op >> b;

            if(op == "=") gr[a].pb(b), gr[b].pb(a); // if '=' push in graph
            else ed.pb({a, b});                     // if '!=' push in edgeList
        }

        // count cc
        rp(i, n) if(vis[i] == 0) dfs(i), curr_cc++;

        // if any var lie in diff cc return false
        flag = true;
        fr(i, ed.size()) if(cc[ed[i].ff] == cc[ed[i].ss]) { flag = false; break; }

        // print res
        if(flag) pr "YES" << endl; else pr "NO" << endl;
    }
}