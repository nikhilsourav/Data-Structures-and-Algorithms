/*
    BFS -> printing indices
    without for loop and 
    dx[] dy[] array
*/
#include <bits/stdc++.h>
using namespace std;

// Global vars
int row;
int col;

// Check if cell is valid
bool is_valid(
    int x,
    int y,
    vector<vector<bool>> &vis,
    vector<vector<char>> &grid)
{
    if (x < 0 || x > row - 1)
        return false;

    if (y < 0 || y > col - 1)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

// bfs
void bfs(
    int x,
    int y,
    vector<vector<bool>> &vis,
    vector<vector<char>> &grid)
{
    // first cell
    vis[x][y] = 1;
    cout << x << " " << y << " " << grid[x][y] << "\n";

    // init queue, push first cell
    queue<pair<int, int>> qu;
    qu.push({x, y});

    // subsequent nodes
    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        qu.pop();

        // right
        if (is_valid(cur.first, cur.second + 1, vis, grid))
        {
            vis[cur.first][cur.second + 1] = 1;
            qu.push({cur.first, cur.second + 1});

            cout << cur.first << " " << cur.second + 1 << " "
                 << grid[cur.first][cur.second + 1] << "\n";
        }

        // bottom
        if (is_valid(cur.first + 1, cur.second, vis, grid))
        {
            vis[cur.first + 1][cur.second] = 1;
            qu.push({cur.first + 1, cur.second});

            cout << cur.first + 1 << " " << cur.second << " "
                 << grid[cur.first + 1][cur.second] << "\n";
        }

        // left
        if (is_valid(cur.first, cur.second - 1, vis, grid))
        {
            vis[cur.first][cur.second - 1] = 1;
            qu.push({cur.first, cur.second - 1});

            cout << cur.first << " " << cur.second - 1 << " "
                 << grid[cur.first][cur.second - 1] << "\n";
        }

        // up
        if (is_valid(cur.first - 1, cur.second, vis, grid))
        {
            vis[cur.first - 1][cur.second] = 1;
            qu.push({cur.first - 1, cur.second});

            cout << cur.first - 1 << " " << cur.second << " "
                 << grid[cur.first - 1][cur.second] << "\n";
        }
    }
}
// Driver code
int main()
{
    // Given grid
    vector<vector<char>> grid =
        {{'#', '#', '@', '#', '#'},
         {'#', '@', '@', '@', '#'},
         {'@', '#', '#', '#', '#'},
         {'#', '#', '@', '@', '#'},
         {'#', '#', '#', '#', '@'}};

    // Set row and col
    row = grid.size();
    col = grid[0].size();

    // Create vis array
    vector<vector<bool>> vis(row, vector<bool>(col, 0));

    // bfs starting from 2 2
    bfs(2, 2, vis, grid);
}