#include <bits/stdc++.h>
using namespace std;

// Global const
const int ROW = 3;
const int COLUMN = 4;

// Print spiral pattern
vector<int> printSpiral(int matrix[ROW][COLUMN])
{
    // init vars
    int top = 0, bottom = ROW - 1, left = 0, right = COLUMN - 1;

    // answer vector
    vector<int> result(ROW * COLUMN);
    int pointer = 0;

    // logic:
    while (top <= bottom && left <= right)
    {
        // left to right
        for (int col = left; col <= right; col++)
            result[pointer++] = matrix[top][col];

        // check
        if (++top > bottom)
            break;

        // top to bottom
        for (int row = top; row <= bottom; row++)
            result[pointer++] = matrix[row][right];

        // check
        if (--right < left)
            break;

        // right to left
        for (int col = right; col >= left; col--)
            result[pointer++] = matrix[bottom][col];

        // check
        if (--bottom < top)
            break;

        // bottom to top
        for (int row = bottom; row >= top; row--)
            result[pointer++] = matrix[row][left];

        // check
        if (++left > right)
            break;
    }

    // answer
    return result;
}

// utility fn print normal matrix
void print(int matrix[ROW][COLUMN])
{
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COLUMN; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }

    cout << "\n";
}

// Driver code
int main()
{
    // Given matrix
    int matrix[ROW][COLUMN] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

    // print given matrix
    cout << "Given matrix:\n";
    print(matrix);

    // print spiral matrix
    cout << "Spiral pattern:\n";
    vector<int> answer = printSpiral(matrix);
    for (auto x : answer)
        cout << x << " ";
}