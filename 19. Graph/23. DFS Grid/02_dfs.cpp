/*
    Notes:
        1. Grid is not same as adj matrix
        2. Vis array is now 2D
        3. Before moving to a cell we need to
           check if it is possible to move into
           that cell i.e., if vis[x][y] == 0 and
           cell is valid (cell index should exist)
        4. In this code grid is in range [0,0, row,col)
*/
#include <bits/stdc++.h>
using namespace std;

// Global values
int row;
int col;
bool vis[100][100];
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};
const int sz = 4;

// Checks if index is valid
bool isValid(int x, int y)
{
    if (x < 0 or x > row - 1 or y < 0 or y > col - 1)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

// DFS
void dfs(int x, int y, vector<vector<int>> &grid)
{
    // visit and print
    vis[x][y] = 1;
    cout << x << " " << y << " => " << grid[x][y] << "\n";

    // recur for further nodes
    for (int i = 0; i < sz; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i], grid);
}

// Driver code
int main()
{
    // Given grid
    vector<vector<int>> grid = {{0, 0, 0, 1, 0},
                                {3, 0, 4, 5, 0},
                                {0, 2, 0, 0, 6},
                                {0, 0, 7, 0, 0}};

    // set global val
    row = grid.size();
    col = grid[0].size();

    int start_x = 0;
    int start_y = 0;

    // fn call
    dfs(start_x, start_y, grid);
}