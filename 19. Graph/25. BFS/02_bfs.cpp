/*
    BFS -> printing indices with
    for loop and dx[] dy[] array
*/
#include <bits/stdc++.h>
using namespace std;

// Global variables
int ROW;
int COL;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Function to check if cell is valid
bool is_valid(
    int x,
    int y,
    vector<vector<bool>> &vis)
{
    if (x < 0 || x > ROW - 1)
        return false;

    if (y < 0 || y > COL - 1)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

// Breadth first search
void bfs(
    int x,
    int y,
    vector<vector<bool>> &vis)
{
    /*
        mark current node as visited
        and print the index. Push it
        into a queue
    */
    vis[x][y] = 1;
    cout << x << " " << y << "\n";

    queue<pair<int, int>> qu;
    qu.push({x, y});

    /*
        repeat this while queue is not
        empty
    */
    while (!qu.empty())
    {
        /*
            take out first element
        */
        pair<int, int> cur = qu.front();
        qu.pop();

        /*
            call for its neighbor
        */
        for (int i = 0; i < 4; i++)
        {
            if (is_valid(cur.first + dx[i], cur.second + dy[i], vis))
            {
                qu.push({cur.first + dx[i], cur.second + dy[i]});
                vis[cur.first + dx[i]][cur.second + dy[i]] = 1;
                cout << cur.first + dx[i] << " " << cur.second + dy[i] << "\n";
            }
        }
    }
}

//  Driver code
int main()
{
    //  Set global vars
    ROW = COL = 3;

    //  Create vis array
    vector<vector<bool>> vis(ROW, vector<bool>(COL, 0));

    // fn call starting from 0 0
    bfs(0, 0, vis);
}