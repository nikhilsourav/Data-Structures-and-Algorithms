/*
    https://www.spoj.com/problems/BUGLIFE/


    Professor Hopper is researching the sexual behavior of a rare species of bugs.
    He assumes that they feature two different genders and that they only interact
    with bugs of the opposite gender. In his experiment, individual bugs and their
    interactions were easy to identify, because numbers were printed on their backs.

    Given a list of bug interactions, decide whether the experiment supports his
    assumption of two genders with no homosexual bugs or if it contains some bug
    interactions that falsify it.

    Input
    The first line of the input contains the number of scenarios. Each scenario
    starts with one line giving the number of bugs (at least one, and up to 2000)
    and the number of interactions (up to 1000000) separated by a single space.
    In the following lines, each interaction is given in the form of two distinct
    bug numbers separated by a single space. Bugs are numbered consecutively
    starting from one.

    Output
    The output for every scenario is a line containing “Scenario #i:”, where i is
    the number of the scenario starting at 1, followed by one line saying either
    “No suspicious bugs found!” if the experiment is consistent with his assumption
    about the bugs’ sexual behavior, or “Suspicious bugs found!” if Professor Hopper’s
    assumption is definitely wrong.

    Example
    Input:
    2
    3 3
    1 2
    2 3
    1 3
    4 2
    1 2
    3 4

    Output:
    Scenario #1:
    Suspicious bugs found!
    Scenario #2:
    No suspicious bugs found!
*/
#include <bits/stdc++.h>
using namespace std;

// Global vars
vector<int> gr[2001];
int vis[2001];
int col[2001];

// Depth first search
bool dfs(int node, int c)
{
    vis[node] = 1;
    col[node] = c;

    for (int child : gr[node])
    {
        if (vis[child] == 0)
        {
            if (dfs(child, !c) == false)
                return false;
        }
        else
        {
            if (col[node] == col[child])
                return false;
        }
    }
    return true;
}

// Driver code
int main()
{
    // local variables
    int t, v, e, a, b;
    cin >> t;

    // test cases
    for (int tc = 1; tc <= t; tc++)
    {
        cin >> v >> e;

        // clear previous inputs
        for (int i = 1; i <= v; i++)
            gr[i].clear(), vis[i] = 0;

        // build graph
        for (int i = 1; i <= e; i++)
            cin >> a >> b, gr[a].push_back(b), gr[b].push_back(a);

        // check bipartites
        bool flag = true;
        for (int i = 1; i <= v; i++)
        {
            if (vis[i] == 0)
            {
                bool res = dfs(i, 0);
                if (res == false)
                    flag = false;
            }
        }

        // don't forget the semicolon
        cout << "Scenario #" << tc << ":" << endl;

        // if graph isBipartite
        if (flag == true)
            cout << "No suspicious bugs found!\n";
        // if graph is not bipartite
        else
            cout << "Suspicious bugs found!\n";
    }

    return 0;
}