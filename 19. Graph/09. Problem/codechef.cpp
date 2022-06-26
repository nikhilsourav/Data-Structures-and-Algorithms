/*
    Question: https://www.codechef.com/problems/FIRESC
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
#define MAX 100001
vector<int>gr[MAX];
bool vis[MAX];
in cnt;

// DFS
void dfs(int src)
{
    vis[src] = 1;
    cnt++;
    for (int ch : gr[src])
        if (vis[ch] == 0)
            dfs(ch);
}

// Driver code
int main()
{
    // fast io
    fastio;

    // local varialbes
    int t, n, m, a, b;
    cin >> t;
    
    // test cases
    while(t--)
    {
        // nodes
        cin >> n >> m;

        // clear previous inputs
        fr(i, n) gr[i].clear(), vis[i] = 0;

        // input nodes
        while(m--) cin >> a >> b, gr[a].push_back(b), gr[b].push_back(a);

        // count connected components
        in cc = 0, res = 1;
        fr(i, n)
        {
            if(vis[i] == false)
            {
                cnt = 0;
                dfs(i), cc++;
                res = (res * cnt) % mod;
            }
        }

        // print res
        cout << cc << " " << res << "\n";
    }
}