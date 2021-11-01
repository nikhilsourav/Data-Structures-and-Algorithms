/*
    Left rotate array by k units
    eg: [1,2,3,4,5] => [3,4,5,1,2] (rotate left by 2 unit)
*/

#include <bits/stdc++.h>
using namespace std;

// Reverse array from low to high
void reverse(int *arr, int low, int high)
{
    while (low <= high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

// Rotate left by k units
void rotateLeftByK(int *arr, int size, int k)
{
    // if k > size
    k %= size;

    // rotate left logic
    reverse(arr, 0, k - 1);
    reverse(arr, k, size - 1);
    reverse(arr, 0, size - 1);
}

// Utility fn
void print(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int k = 6;

    // fn call
    rotateLeftByK(arr, size, k);

    // Output
    print(arr, size);
}