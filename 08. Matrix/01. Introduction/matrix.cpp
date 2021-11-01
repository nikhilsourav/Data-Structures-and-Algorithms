#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // Matrix of 3 rows and 2 columns
    int row = 3, column = 2;

    /*  ============== Variable Sized ================ */
    int arr1[row][column] = {{10, 10}, {10, 10}, {10, 10}}; // nested braces are optional

    // Output
    cout << "Varialbe Sized\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << arr1[i][j] << " ";
        cout << "\n";
    }

    /*
        ============== Double pointer ================
        * arr2 itself is a pointer so to acces arr2[0] we write print(*arr2[0])
        * arr2 gets memory in Heap
    */
    int **arr2;
    arr2 = new int *[row];
    for (int i = 0; i < row; i++)
        arr2[i] = new int[column]; // size of each row (can be variable)

    // Initialize and print
    cout << "Double Pointer\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            arr2[i][j] = 20;
            cout << arr2[i][j] << " ";
        }
        cout << "\n";
    }

    /*
        ============== Array of Pointers ================ 
        * arr3 is not a pointer so to acces arr3[0] we write print(arr3[0])
        * arr3 gets memory in Stack
    */
    int *arr3[row];
    for (int i = 0; i < row; i++)
        arr3[i] = new int[column]; // size of each row (can be variable)

    // Initialize and print
    cout << "Array of Pointers\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
        {
            arr3[i][j] = 30;
            cout << arr3[i][j] << " ";
        }
        cout << "\n";
    }

    /* ============== Array of Vectors ================ */
    vector<int> arr4[row];

    // Initialization
    for (int i = 0; i < row; i++)
        for (int j = 0; j < column; j++)
            arr4[i].push_back(40);

    // Output
    cout << "Array of Vectors\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << arr4[i][j] << " ";
        cout << "\n";
    }

    /*  ============== Vector of vectors ================  */
    vector<vector<int>> arr5;

    // Initialization method 1:
    for (int i = 0; i < row; i++)
    {
        vector<int> v;
        for (int j = 0; j < column; j++)
            v.push_back(50);
        arr5.push_back(v);
    }

    // Output
    cout << "Vector of Vectors Method 1\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << arr5[i][j] << " ";
        cout << "\n";
    }

    // Initialization method 2:
    arr5.clear();
    vector<int> v1 = {50, 50};
    vector<int> v2 = {50, 50};
    vector<int> v3 = {50, 50};
    arr5.push_back(v1);
    arr5.push_back(v2);
    arr5.push_back(v3);

    // Output
    cout << "Vector of Vectors Method 2\n";
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << arr5[i][j] << " ";
        cout << "\n";
    }
}