#include <bits/stdc++.h>
using namespace std;

// Transpose (in-place for square matrix only)
void transposeSquareMatrix(vector<vector<int>> &matrix)
{
    // transpose logic for square matrix
    for (int i = 0; i < matrix.size(); i++)
        for (int j = i + 1; j < matrix.size(); j++)
            swap(matrix[i][j], matrix[j][i]);
}

// Transpose (general case)
vector<vector<int>> transposeGeneral(vector<vector<int>> &matrix)
{
    // temp vector of size 4 x 3 (matrix is of size 3 x 4)
    vector<vector<int>> transposed(matrix[0].size(), vector<int>(matrix.size()));

    // transpose logic:
    for (int i = 0; i < matrix.size(); i++)
        for (int j = 0; j < matrix[i].size(); j++)
            transposed[j][i] = matrix[i][j];

    // answer
    return transposed;
}

// Utility fn to print normal matrix
void print(vector<vector<int>> &matrix)
{
    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Driver code
int main()
{
    // Given matrices
    vector<vector<int>> matrix1 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};
    vector<vector<int>> matrix2 = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // Print given matrix
    cout << "Given square matrix:\n";
    print(matrix1);

    // fn call
    transposeSquareMatrix(matrix1);

    // Print output
    cout << "\nTransposed square matrix:\n";
    print(matrix1);

    // Print given matrix
    cout << "\nGiven m x n matrix:\n";
    print(matrix2);

    // fn call
    vector<vector<int>> answer = transposeGeneral(matrix2);

    // Print output
    cout << "\nTransposed m x n matrix:\n";
    print(answer);
}