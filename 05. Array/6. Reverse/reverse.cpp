#include <bits/stdc++.h>
using namespace std;

// reverse array
void reverseArr(int *arr, int size)
{
    // init vars
    int low = 0, high = size - 1, temp;

    // logic:
    while (low < high)
    {
        swap(arr[low], arr[high]);
        low++;
        high--;
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // reverse
    reverseArr(arr, size);

    // output
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
}