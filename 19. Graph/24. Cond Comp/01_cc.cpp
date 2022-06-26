#include <bits/stdc++.h>
using namespace std;

// Global vars
int row;
int col;
const int sz = 4;

int grid[1001][1001];
bool vis[100][100];

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

// Checks if index is valid
bool isValid(int x, int y)
{
    if (x < 0 or x > row - 1 or y < 0 or y > col - 1)
        return false;

    if (vis[x][y] == 1 or grid[x][y] == 0)
        return false;

    return true;
}

// DFS
void dfs(int x, int y)
{
    // visit and print
    vis[x][y] = 1;

    // recur for further nodes
    for (int i = 0; i < sz; i++)
        if (isValid(x + dx[i], y + dy[i]))
            dfs(x + dx[i], y + dy[i]);
}

// Driver code
int main()
{

    /*
        Inputs:
            6 6
            0 0 1 0 1 1
            0 1 1 0 0 1
            0 1 0 0 0 0
            1 0 1 1 0 0
            0 0 0 1 0 0
            0 1 1 0 1 1
    */
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < row; j++)
            cin >> grid[i][j];

    // fn call
    int cc = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (vis[i][j] == 0 and grid[i][j] == 1)
                dfs(i, j), cc++;

    cout << "\nconnected components: " << cc << endl;
}