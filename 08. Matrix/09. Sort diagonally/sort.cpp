/*
    Sort matrix diagonally
    A matrix diagonal is a diagonal line of cells
    starting from some cell in either the topmost row
    or leftmost column and going in the bottom-right
    direction until reaching the matrix's end.

    For example, the matrix diagonal starting from
    mat[2][0], where mat is a 6 x 3 matrix, includes
    cells mat[2][0], mat[3][1], and mat[4][2].

    Given an m x n matrix mat of integers, sort each
    matrix diagonal in ascending order and return the
    resulting matrix.

    https://leetcode.com/problems/sort-the-matrix-diagonally/
*/

#include <bits/stdc++.h>
using namespace std;

// Sort matrix diagonally
vector<vector<int>> diagonalSort(vector<vector<int>> &mat)
{
    // init map
    unordered_map<int, vector<int>> mp;

    // init row and column
    int m = mat.size();
    int n = mat[0].size();

    // store value in map
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            mp[i - j].push_back(mat[i][j]);

    // sort
    for (int k = -(n - 1); k < m; k++)
        sort(mp[k].begin(), mp[k].end());

    // put value back in matrix
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            mat[i][j] = mp[i - j].back();
            mp[i - j].pop_back();
        }
    }

    // answer
    return mat;
}

// Driver code
int main()
{
    // Given matrix
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {1, 2, 3, 4},
                                  {5, 6, 7, 8}};

    // fn call
    vector<vector<int>> ans = diagonalSort(matrix);

    // Output
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}