/*
    Find median in two sorted array
    https://bit.ly/3BCjuR0
*/

#include <bits/stdc++.h>
using namespace std;

// Find median in two sorted array O(log min(n1,n2))
float median(int arr1[], int arr2[], int size1, int size2)
{
    // swap length if siz1 > size2
    if (size1 > size2)
        return median(arr1, arr2, size2, size1);

    // initialize low and high based on smaller array (in this case arr1)
    int low = 0, high = size1;

    // logic:
    while (low <= high)
    {
        // calculate the partition
        int partitionX = (low + high) / 2;
        int partitionY = ((size1 + size2 + 1) / 2) - partitionX;

        // corener cases
        int maxLeftX = (partitionX == 0) ? INT_MIN : arr1[partitionX - 1];
        int minRightX = (partitionX == size1) ? INT_MAX : arr1[partitionX];
        int maxLeftY = (partitionY == 0) ? INT_MIN : arr2[partitionY - 1];
        int minRightY = (partitionY == size2) ? INT_MAX : arr2[partitionY];

        // if found
        if ((maxLeftX <= minRightY) && (maxLeftY <= minRightX))
        {
            // combined array is even
            if ((size1 + size2) % 2 == 0)
                return (double)((max(maxLeftX, maxLeftY) + min(minRightX, minRightY)) / 2);
            // combined array is odd
            else
                return (double)(max(maxLeftX, maxLeftY));
        }
        // move left
        else if (maxLeftX > minRightY)
            high = partitionX - 1;
        // move right
        else
            low = partitionX + 1;
    }

    // to avoid warnings
    return INT_MIN;
}

// Driver code
int main()
{
    // Given two sorted array
    int arr1[] = {1, 3, 8, 9, 15};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {7, 11, 18, 19, 21, 25};
    int size2 = sizeof(arr2) / sizeof(arr2[0]);

    // fn call
    cout << median(arr1, arr2, size1, size2);
}