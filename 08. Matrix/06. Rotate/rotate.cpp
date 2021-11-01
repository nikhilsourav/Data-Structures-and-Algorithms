#include <bits/stdc++.h>
using namespace std;

// Global const
const int SIZE = 4;

// Utility fn to print
void print(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
            cout << matrix[i][j] << " ";
        cout << "\n";
    }
}

// Rotate 90 deg anticlockwise (transpose and reverse each column)
void rotateLeft(int matrix[SIZE][SIZE])
{
    // transpose
    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
            swap(matrix[i][j], matrix[j][i]);

    // reverse
    for (int i = 0; i < SIZE; i++)
    {
        int low = 0, high = SIZE - 1;

        while (low < high)
        {
            swap(matrix[low][i], matrix[high][i]);

            low++;
            high--;
        }
    }
}

// Rotate 90 deg clockwise (transpose and reverse each row)
void rotateRight(int matrix[SIZE][SIZE])
{
    // transpose
    for (int i = 0; i < SIZE; i++)
        for (int j = i + 1; j < SIZE; j++)
            swap(matrix[i][j], matrix[j][i]);

    // reverse
    for (int i = 0; i < SIZE; i++)
    {
        int low = 0, high = SIZE - 1;

        while (low < high)
        {
            swap(matrix[i][low], matrix[i][high]);

            low++;
            high--;
        }
    }
}

// Driver code
int main()
{
    // Given matrix
    int matrix[SIZE][SIZE] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 16}};

    // Print given matrix
    cout << "Given matrix:\n";
    print(matrix);

    // fn call
    rotateLeft(matrix);

    // Print output
    cout << "\nRotated 90 deg anti-clockwise:\n";
    print(matrix);

    // fn call
    rotateRight(matrix); // counter first rotation
    rotateRight(matrix); // rotate right given matrix

    // Print output
    cout << "\nRotated 90 deg clockwise:\n";
    print(matrix);
}