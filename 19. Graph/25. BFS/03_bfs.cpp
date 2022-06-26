/*
    BFS -> distance array starting
    from a node
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
    vector<vector<bool>> &vis,
    vector<vector<int>> &dist)
{
    /*
        mark first node as visited and
        print it's index. Push it into
        the queue. Set its distance = 0
    */
    vis[x][y] = 1;
    // cout << x << " " << y << "\n";

    queue<pair<int, int>> qu;
    qu.push({x, y});

    dist[x][y] = 0;

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
            call for its neighbor and
            set distance accordingly
        */
        for (int i = 0; i < 4; i++)
        {
            if (is_valid(cur.first + dx[i], cur.second + dy[i], vis))
            {
                vis[cur.first + dx[i]][cur.second + dy[i]] = 1;
                qu.push({cur.first + dx[i], cur.second + dy[i]});

                dist[cur.first + dx[i]][cur.second + dy[i]] = dist[cur.first][cur.second] + 1;
                // cout << cur.first + dx[i] << " " << cur.second + dy[i] << "\n";
            }
        }
    }

    /*
        print distance array
    */
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
}

//  Driver code
int main()
{
    //  Set global vars
    ROW = COL = 5;

    //  Create vis array
    vector<vector<bool>> vis(ROW, vector<bool>(COL, 0));
    vector<vector<int>> dist(ROW, vector<int>(COL, 0));

    // fn call starting from (srcX,srcY)
    int srcX = 3, srcY = 3;

    bfs(srcX, srcY, vis, dist);
}