#include <bits/stdc++.h>
using namespace std;
#define MAX 10001

// Global vars
vector<int> gr[MAX];
int vis[MAX];

// Check cycle
bool hasCycle(int s, int parent)
{
    vis[s] = 1;

    for (auto ch : gr[s])
    {
        if (vis[ch] == false)
        {
            if (hasCycle(ch, s) == true)
                return true;
        }
        else
        {
            if (parent != ch)
                return true;
        }
    }

    return false;
}

// Driver code
int main()
{
    /*
          1
         /
        2
       / \
      3 - 4
            \
             6
    */

    // build graph
    gr[1].push_back(2);
    gr[2].push_back(1);
    gr[2].push_back(3);
    gr[2].push_back(4);
    gr[3].push_back(2);
    gr[3].push_back(4);
    gr[4].push_back(2);
    gr[4].push_back(6);
    gr[6].push_back(4);

    // fn call
    cout << boolalpha << hasCycle(1, -1);
}