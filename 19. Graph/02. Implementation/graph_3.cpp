#include <bits/stdc++.h>
using namespace std;

// fast io
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL)

// keywords
#define pb push_back
#define endl '\n'

// constants
#define MOD 1'000'000'007
#define ERR exit(0)

// containers
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(), x.end()

// loops
#define fr(i, n) for (int i = 0; i < n; i++)
#define rep(i, n) for (int i = 1; i <= n; i++)

// print
#define pr cout <<
#define deb(x) pr #x << " = " << x << endl;
template <typename T> void prv(vector<T> v) {fr(i, v.size()) pr v[i] << " "; pr endl;}
template <typename T> void prvv(vector<T> v) {fr(i, v.size()) {fr(j, v[i].size()) pr v[i][j] << " "; pr endl;}}

// ============ Code ============ //
class Graph
{
public:
    vvi gr; // adjacency list
    vi vis; // visited list
    int v;  // num of vertices

    // Undirected graph constructor
    Graph(vvi ed, int v)
    {
        this->v = v; vis.resize(v + 1, 0); gr.resize(v + 1); 
        fr(i, ed.size()) gr[ed[i][0]].pb(ed[i][1]), gr[ed[i][1]].pb(ed[i][0]);
    }

    // Print adjacency list
    void prgr()
    {
        rep(i, v) { pr i << ": "; fr(j, gr[i].size()) pr gr[i][j] << " "; pr endl; }
    }

    // dfs
    void dfs(int src)
    {
        vis[src] = 1; pr src << " "; for(int ch: gr[src]) if(vis[ch] == 0) dfs(ch);
    }

    void bfs(int src)
    {
        fill(all(vis), 0); // reset vis array
        queue<int> qu; vis[src] = 1; qu.push(src);
        while(!qu.empty())
        {
            int cur = qu.front(); qu.pop(); pr cur << " ";
            for(int ch: gr[cur]) if(vis[ch] == 0) vis[ch] = 1, qu.push(ch);
        }
    }
};

int main()
{
    fastio;

    vvi a = {{1,2},{1,5},{1,6},{1,3},{2,5},{2,7},{3,4},{5,6}};
    Graph g(a, 7);
    g.prgr();
    g.dfs(1);
    pr endl;
    g.bfs(1);
}
// ============ Code ============ //
