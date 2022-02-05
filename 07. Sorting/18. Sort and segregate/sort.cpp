/*
    Given an array that consists of only '0', '1' and '2'
    integer values. Sort the array

    https://www.youtube.com/watch?v=oaVa-9wmpns
*/

#include <bits/stdc++.h>
using namespace std;

// Sort array of 0, 1, 2
void sort012(int arr[], int size)
{
    // init vars
    int low = 0, mid = 0, high = size - 1;

    // logic:
    while (mid <= high)
    {
        switch (arr[mid])
        {
        // if element is 0
        case 0:
            swap(arr[low++], arr[mid++]);
            break;

        // if element is 1
        case 1:
            mid++;
            break;

        // if element is 2
        case 2:
            swap(arr[high--], arr[mid]);
            break;
        }
    }
}

/*
    Given an array of positive and negative integer values.
    Segregate all -ve followed by all +ve values
*/

void segregatePosNeg(int arr[], int size)
{
    // init vars:
    int i = -1, j = size;

    // logic:
    while (true)
    {
        // increment i
        do
        {
            i++;
        } while (arr[i] < 0);

        // decrement j
        do
        {
            j--;
        } while (arr[j] >= 0);

        // base case
        if (i >= j)
            return;

        // if base case false, swap
        swap(arr[i], arr[j]);
    }
}

// Driver code
int main()
{
    // Given array
    int arr1[] = {0, 1, 0, 2, 1, 0, 1, 0};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    // sort 0, 1 and 2
    sort012(arr1, n1);

    // Output
    for (auto x : arr1)
        cout << x << " ";

    // Given array
    int arr2[] = {-12, 19, -10, 15};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // Segregate +ve and -ve
    segregatePosNeg(arr2, n2);

    // Output
    cout << "\n";
    for (auto x : arr2)
        cout << x << " ";
}
