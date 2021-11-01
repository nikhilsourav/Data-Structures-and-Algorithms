/*
    Print content of array using pointers
*/

#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Init pointer
    int *ptr = arr;

    // Print array contents using pointer
    for (int i = 0; i < n; i++)
        cout << (*ptr)++ << " ";
}

/*
    NOTES:

    => we can't decrement pointer once incremented that is p-- won't work.
    => arr[i] is same as *(arr + i)
    => &arr[i] is same as (arr + i)
    => arr[i][j] is same as *(*(arr + i) + j)
    => int arr[] = {1, 2, 3}; arr++; ERROR
*/