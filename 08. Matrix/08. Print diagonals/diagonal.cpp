// C++ Program to print the Diagonals of a Matrix
#include <bits/stdc++.h>
using namespace std;

// Global const
const int row = 100;
const int col = 100;

// Function to print the Principal Diagonal
void printPrincipalDiagonal(int mat[row][col], int n)
{
	// msg
	cout << "Principal Diagonal: ";

	// logic:
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Condition for principal diagonal
			if (i == j)
				cout << mat[i][j] << ", ";
		}
	}

	// newline
	cout << "\n";
}

// Function to print the Secondary Diagonal
void printSecondaryDiagonal(int mat[row][col], int n)
{
	// msg
	cout << "Secondary Diagonal: ";

	// logic:
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			// Condition for secondary diagonal
			if (i == (n - j - 1))
				cout << mat[i][j] << ", ";
		}
	}

	// newline
	cout << "\n";
}

// Driver code
int main()
{
	// Given array
	int array[row][col] = {{1, 2, 3, 4},
						   {5, 6, 7, 8},
						   {1, 2, 3, 4},
						   {5, 6, 7, 8}};
	int size = 4;

	// fn call
	printPrincipalDiagonal(array, size);
	printSecondaryDiagonal(array, size);
}
