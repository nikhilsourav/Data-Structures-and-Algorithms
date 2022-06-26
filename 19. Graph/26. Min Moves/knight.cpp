/*
    Yeet Question: https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1/

    Input:
        K = 4,5
        T = 1,1
        N = 6

        # # # # # #
        # # # K # #
        # # # # # #
        # # # # # #
        # # # # # #
        T # # # # #

    Consider the 7x7 arrangement:

    # # # # # # #    S = Source (Initial position of knight)
    # # K # K # #    K = Position knight can reach with 1 move
    # K # # # K #
    # # # S # # #
    # K # # # K #    Possible moves:
    # # K # K # #    (x-2,y+1) (x-1,y+2) (x+1,y+2) (x+2,y+1)
    # # # # # # #    (x+2,y-1) (x+1,y-2) (x-1,y-2) (x-2,y-1)

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    Algorithm:
        1. Start bfs from source (why bfs => guarantees shortest path)
        2. Explore nodes and store their distances in dist[] array
           next node dist = prev node dist + 1
        3. As soon as index of T (ty, ty) found, return dist[tx][ty]
        4. If T not found return dist[tx][ty] which already has -1
*/

#include <bits/stdc++.h>
using namespace std;

bool isValid(
    int x,
    int y,
    int N,
    vector<vector<bool>> &vis)
{
    if (x < 1 || x > N)
        return false;
    if (y < 1 || y > N)
        return false;

    if (vis[x][y] == 1)
        return false;

    return true;
}

// Given function
int minStepToReachTarget(
    vector<int> &KnightPos,
    vector<int> &TargetPos,
    int N)
{
    int sx = KnightPos[0];
    int sy = KnightPos[1];

    int tx = TargetPos[0];
    int ty = TargetPos[1];

    vector<vector<bool>> vis(N + 1, vector<bool>(N + 1, 0));
    vector<vector<int>> dist(N + 1, vector<int>(N + 1, -1));

    // BFS
    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1, 2, 2, 1, -1, -2, -2, -1};

    vis[sx][sy] = 1;
    dist[sx][sy] = 0;

    queue<pair<int, int>> qu;
    qu.push({sx, sy});

    while (!qu.empty())
    {
        pair<int, int> cur = qu.front();
        int X = cur.first;
        int Y = cur.second;
        qu.pop();

        if (X == 0 || Y == 0)
            continue;

        // If found while iterating
        if (X == tx && Y == ty)
            return dist[X][Y];

        for (int i = 0; i < 8; i++)
        {
            int newX = X + dx[i];
            int newY = Y + dy[i];

            if (isValid(newX, newY, N, vis))
            {
                vis[newX][newY] = 1;
                dist[newX][newY] = dist[X][Y] + 1;
                qu.push({newX, newY});
            }
        }
    }

    return dist[tx][ty];
}

// Driver code
int main()
{
    vector<int> KnightPos = {4, 5};
    vector<int> TargetPos = {1, 1};
    int N = 6;

    cout << minStepToReachTarget(KnightPos, TargetPos, N);
}