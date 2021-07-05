#include <bits/stdc++.h>
using namespace std;

// Union of two sorted array
void printUnion(int arr[], int brr[], int m, int n)
{
    // init vars:
    int i = 0, j = 0;

    // logic:
    while (i < m && j < n)
    {
        // handle duplicate for first array
        if (i > 0 && arr[i] == arr[i - 1])
        {
            i++;
            continue;
        }

        // handle duplicate for second array
        if (j > 0 && brr[j] == brr[j - 1])
        {
            j++;
            continue;
        }

        // union logic:
        if (arr[i] < brr[j])
        {
            cout << arr[i] << " ";
            i++;
        }
        else if (arr[i] > brr[j])
        {
            cout << brr[j] << " ";
            j++;
        }
        else
        {
            cout << arr[i] << " ";
            i++;
            j++;
        }
    }

    // remaining unprocessed elements
    while (i < m)
    {
        if (i > 0 && arr[i] != arr[i - 1])
        {
            cout << arr[i] << " ";
            i++;
        }
    }
    while (j < n)
    {
        if (j > 0 && brr[j] != brr[j - 1])
        {
            cout << brr[j] << " ";
            j++;
        }
    }
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 2, 3, 4, 5};
    int brr[] = {1, 2, 3};
    int m = sizeof(arr) / sizeof(arr[0]);
    int n = sizeof(brr) / sizeof(brr[0]);

    // fn call
    printUnion(arr, brr, m, n);
}