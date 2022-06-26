/*
    Given an undirected graph with n nodes and m edges, find
    and print any cycle if exist (print only one cycle)

    1---4
    | / |
    2---3

    valid ans:
    1241
    14321
    2432
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Global vars
vector<int> gr[MAX];
bool vis[MAX];
vector<int> cycle;

// Print cycle
bool printCycle(int s, int parent)
{
    vis[s] = 1;
    cycle.push_back(s);

    for (auto ch : gr[s])
    {
        if (vis[ch] == false)
        {
            if (printCycle(ch, s) == true)
                return true;
        }
        else
        {
            if (parent != ch)
            {
                cycle.push_back(ch);
                return true;
            }
        }
    }

    cycle.pop_back();
    return false;
}

// Driver code
int main()
{
    /*
        1---4
        | / |
        2---3
    */

    // build graph
    gr[1].push_back(4);
    gr[4].push_back(1);

    gr[1].push_back(2);
    gr[2].push_back(1);

    gr[4].push_back(3);
    gr[3].push_back(4);

    gr[2].push_back(4);
    gr[4].push_back(2);

    gr[2].push_back(3);
    gr[3].push_back(2);

    // fn call
    printCycle(1, -1);

    // print first cycle
    cout << cycle.back() << " ";
    for (int i = cycle.size() - 2; i >= 0; i--)
    {
        if (cycle[i] == cycle.back())
        { 
            cout << cycle[i] << " ";
            break;
        }
        cout << cycle[i] << " ";
    }
}