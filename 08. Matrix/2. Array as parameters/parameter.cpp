#include <bits/stdc++.h>
using namespace std;

// Method 1 (using global const int)
const int row = 3;
const int column = 2;

void printMethodOne(int matrix[row][column])
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Method 2 (works only for row x 2 matrix)
void printMethodTwo(int matrix[][2], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Method 3 (pointer of pointers)
void printMethodThree(int **matrix, int row, int column)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Method 4 (array of vectors)
void printMethodFour(vector<int> matrix[], int row)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Method 5 (vector of vectors)
void printMethodFive(vector<vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Print a 2D array without global variables
void printArr(int *arr, int M, int N)
{
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
            cout << *((arr + i * N) + j) << " ";
        cout << "\n";
    }
}

// Driver code
int main()
{
    // Given array
    int arr[][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};

    // fn call
    printArr(&arr[0][0], 3, 3);
}