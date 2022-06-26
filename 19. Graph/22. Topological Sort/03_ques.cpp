/*
    Question: https://www.spoj.com/problems/TOPOSORT/


    Example 1
        Input:
        8 9
        1 4
        1 2
        4 2
        4 3
        3 2
        5 2
        3 5
        8 2
        8 6

        Output:
        1 4 3 5 7 8 2 6

    Example 2
        Input:
            2 2
            1 2
            2 1

        Output:
        Sandro fails.
*/

#include <bits/stdc++.h>
using namespace std;

// fast io
#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL)

// keywords
#define pb push_back

// containers
#define vi vector<int>
#define vvi vector<vector<int>>
#define all(x) x.begin(), x.end()

// loops
#define rp(i, n) for (int i = 1; i <= n; i++)
#define fr(i, n) for (int i = 0; i < n; i++)

// print
#define pr cout <<
#define deb(x) pr #x << " = " << x << endl;
template <typename T>
void prv(vector<T> v)
{
    fr(i, v.size()) pr v[i] << " ";
    pr endl;
}

// ============ Question ============ //
#define MAX 10'001

vi gr[MAX];
int in[MAX];

vi topsort(int n)
{
    priority_queue<int, vi, greater<int>> qu;
    vi res;

    rp(i, n) if (in[i] == 0) qu.push(i);

    while (!qu.empty())
    {
        int cur = qu.top();
        qu.pop();
        res.pb(cur);

        for (int ch : gr[cur])
        {
            in[ch]--;
            if (in[ch] == 0)
                qu.push(ch);
        }
    }

    if (res.size() == n)
        return res;
    return {};
}

// Driver code
int main()
{
    fastio;

#ifndef ONLINE_JUDGE
    freopen("_i.txt", "r", stdin);
    freopen("_o.txt", "w", stdout);
#endif

    int n, m, u, v;
    cin >> n >> m;

    rp(i, n) gr[i].clear();

    while (m--)
        cin >> u >> v, gr[u].pb(v), in[v]++;

    vi res = topsort(n);

    if (res.size() == 0)
        pr "Sandro fails." << endl;
    else
        prv(res);
}
// ============ Question ============ //