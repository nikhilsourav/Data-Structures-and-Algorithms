#include <bits/stdc++.h>
using namespace std;

// merge two sorted array
void merge(int arr[], int brr[], int m, int n)
{
    // init vars
    int i = 0, j = 0;

    // logic of merge
    while (i < m && j < n)
    {
        if (arr[i] <= brr[j])
            cout << arr[i++] << " ";
        else
            cout << brr[j++] << " ";
    }

    // print remaining elements (only one loop is executed)
    while (i < m)
        cout << arr[i++] << " ";
    while (j < n)
        cout << brr[j++] << " ";
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 4, 7};
    int brr[] = {2, 3, 6};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(brr) / sizeof(brr[0]);

    // fn call
    merge(arr, brr, m, n);
}