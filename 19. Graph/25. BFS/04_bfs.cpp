/*
    BFS -> clean
*/
#include <bits/stdc++.h>
using namespace std;

// Global variables
int ROW;
int COL;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
int vis[100][100];
int dist[100][100];

// Function to check if cell is valid
bool is_valid(int x, int y)
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
void bfs(int x, int y)
{
    /*
        Mark first node as visited and
        print it's index. Push it into
        the queue. Set its distance = 0
    */
    vis[x][y] = 1;

    queue<pair<int, int>> qu;
    qu.push({x, y});

    dist[x][y] = 0;

    /*
        Repeat this while queue is not
        empty
    */
    while (!qu.empty())
    {
        /*
            Take out first element
        */
        pair<int, int> cur = qu.front();
        int X = cur.first;
        int Y = cur.second;
        qu.pop();

        /*
            Call for its neighbor and
            set distance accordingly
        */
        for (int i = 0; i < 4; i++)
        {
            int newX = X + dx[i];
            int newY = Y + dy[i];

            if (is_valid(newX, newY))
            {
                vis[newX][newY] = 1;
                qu.push({newX, newY});
                dist[newX][newY] = dist[X][Y] + 1;
            }
        }
    }

    /*
        Print distance array
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

    bfs(srcX, srcY);
}