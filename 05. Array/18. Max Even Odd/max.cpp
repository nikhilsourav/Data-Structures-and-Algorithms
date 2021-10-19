#include <bits/stdc++.h>
using namespace std;

// extension of kaden's algorithm
int maxEvenOdd(int arr[], int size)
{
    // init vars:
    int res = 1;
    int currentLength = 1;

    // loigc:
    for (int i = 0; i < size; i++)
    {
        if ((arr[i] % 2 == 0 && arr[i - 1] % 2 != 0) || (arr[i] % 2 != 0 && arr[i - 1] % 2 == 0))
        {
            currentLength++;
            res = max(res, currentLength);
        }
        else
            currentLength = 1;
    }

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 12, 14, 7, 8, 9, 10, 2};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << maxEvenOdd(arr, size) << "\n";
}