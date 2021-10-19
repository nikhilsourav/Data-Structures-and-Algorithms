#include <bits/stdc++.h>
using namespace std;

// check if sorted in non decreasing order (equals are allowed)
bool checkSorted(int arr[], int size)
{
    // logic
    for (int i = 0; i < size - 1; i++)
        if (arr[i] > arr[i + 1])
            return false;

    // answer
    return true;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 8, 8, 52};
    int size = sizeof(arr) / sizeof(arr[0]);

    // print
    bool isSorted = checkSorted(arr, size);
    isSorted ? cout << "Sorted" : cout << "Not sorted";
}