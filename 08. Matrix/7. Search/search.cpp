#include <bits/stdc++.h>
using namespace std;

const int ROW = 4, COLUMN = 4;

// Given matrix is row-wise and column-wise sorted
void search(int mat[ROW][COLUMN], int target)
{
    // init vars
    int low = 0, high = COLUMN - 1;

    // logic:
    while (low < ROW && high >= 0)
    {
        if (mat[low][high] == target)
        {
            cout << "Found at (" << low << ", " << high << ")";
            return;
        }
        else if (mat[low][high] > target)
            high--;
        else
            low++;
    }

    // if not found
    cout << "Not Found";
}

// Driver code
int main()
{
    // Given array
    int arr[ROW][COLUMN] = {{10, 20, 30, 40}, {15, 25, 35, 45}, {27, 29, 35, 45}, {32, 33, 39, 50}};
    int target = 29;

    // fn call
    search(arr, target);
}

/*
    ALGORITHM: 
    * Begin from top right
    * If target is same, found
    * If target is small move left
    * If target is greater move down
*/