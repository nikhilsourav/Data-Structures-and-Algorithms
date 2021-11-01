/*
    Move a value to the front / back maintaining order
    eg: [1,2,0,3,1,0] => [1,2,3,1,0,0] (move 0 to end)
*/

#include <bits/stdc++.h>
using namespace std;

// Move all occurances of val to end O(n)
void segregateBack(int *arr, int size, int val)
{
    // A pointer to value
    int pointer = 0;

    // segregate elements to end
    for (int i = 0; i < size; i++)
    {
        if (arr[i] != val)
        {
            swap(arr[i], arr[pointer]);
            pointer++;
        }
    }
}

// Move all occurances of val to front O(n)
void segregateFront(int *arr, int size, int val)
{
    // pointer to value
    int pointer = size - 1;

    // segregate elements to front
    for (int i = size - 1; i >= 0; i--)
    {
        if (arr[i] != val)
        {
            swap(arr[i], arr[pointer]);
            pointer--;
        }
    }
}

// Utility fn to print
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
    int arr[] = {8, 5, 0, 10, 0, 7, 0, 10, 0, 10};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Output given array
    cout << "----------before----------\n";
    print(arr, size);

    // Function call
    segregateFront(arr, size, 10);

    // Output after segregation
    cout << "----------after----------\n";
    print(arr, size);
}