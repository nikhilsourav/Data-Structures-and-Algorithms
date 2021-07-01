/*
    Peak element:
        an element such that arr[i-1] <= arr[i] <= arr[i+1]
        first and last elements are always peak elements.
    fact: 
        if left of mid element is >= mid element then there will always
        be a peak in left half, otherwise there will be a peak in right half
*/

#include <bits/stdc++.h>
using namespace std;

// find peak element O(log n)
int peak(int arr[], int size)
{
    // low and high vars for binary search
    int low = 0, high = size - 1;
    while (low <= high)
    {
        // compute mid
        int mid = (low + high) / 2;

        // if element is found (logic: definition of peak element)
        if ((mid == 0 || arr[mid - 1] <= arr[mid]) && (mid == size - 1 || arr[mid + 1] <= arr[mid]))
            return arr[mid];

        // if left of mid element is greater, go to left half
        if (mid > 0 && arr[mid - 1] >= arr[mid])
            high = mid - 1;
        // otherwise go to right half
        else
            low = mid + 1;
    }

    // if no peak element
    return -1;
}

// O(logN) my soln
int peakIndexInMountainArray(vector<int> &arr)
{
    // compute size and declare low, high vars
    int size = arr.size() - 1;
    int low = 0, high = size;

    // logic:
    while (low <= high)
    {
        // compute mid
        int mid = (low + high) / 2;

        // corner case, if mid == 0 or mid == last index
        if ((mid == 0 && arr[mid] > arr[mid + 1]) || (mid == size && arr[mid] > arr[mid - 1]))
            return mid;
        // if mid == 0 and next element is greater, go right
        else if (mid == 0 && arr[mid + 1] > arr[mid])
            low = mid + 1;
        // if mid == size and prev element is greater go to left
        else if (mid == size && arr[mid - 1] > arr[mid])
            high = mid - 1;
        // if 0 < mid < last index (both excluded as they're checked earlier)
        else if ((arr[mid] > arr[mid + 1]) && (arr[mid] > arr[mid - 1]))
            return mid;
        // if arr[mid-1] > arr[mid], peak element must be in left half, move left
        else if (arr[mid - 1] > arr[mid])
            high = mid - 1;
        // otherwise move right
        else
            low = mid + 1;
    }

    // if not found (never executed);
    return -1;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {5, 10, 20, 125, 7};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << peak(arr, size) << "\n";

    // Given vector
    vector<int> vrr = {0, 1, 0, 0, 3, 2};

    // fn call
    cout << peakIndexInMountainArray(vrr);
}