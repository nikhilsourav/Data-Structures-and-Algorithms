#include <bits/stdc++.h>
using namespace std;

// Utility
#define deb(x) cout << #x << " = " << x << endl
template <typename T>
void prvv(vector<T> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
}

// Global variable
int row;
int col;
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

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

    if (vis[x][y] == true || grid[x][y] == '#')
        return false;

    return true;
}

// DFS
void dfs(
    int x,
    int y,
    vector<vector<bool>> &vis,
    vector<vector<char>> &grid)
{
    vis[x][y] = 1;
    cout << x << " " << y << " " << grid[x][y] << endl;

    // right
    for (int i = 0; i < 4; i++)
        if (is_valid(x + dx[i], y + dy[i], vis, grid))
            dfs(x + dx[i], y + dy[i], vis, grid);
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

    // Count connected components
    int cc = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (vis[i][j] == false and grid[i][j] == 'o')
                dfs(i, j, vis, grid), cc++, cout << endl;

    // Print connected components
    deb(cc);
}