#include <bits/stdc++.h>
using namespace std;

// search an element in a sorted and rotated array. O(logn)
int search(int nums[], int size, int target)
{
    // initialize low and high variables
    int low = 0, high = size - 1;

    // logic
    while (low <= high)
    {
        // compute mid
        int mid = (low + high) / 2;

        // check middle element (base case)
        if (nums[mid] == target)
            return mid;

        // left half is sorted
        if (nums[low] <= nums[mid])
        {
            if (target >= nums[low] && target < nums[mid]) // target <= nums[mid] is not required because equality has already been checked earlier
                high = mid - 1;                            // go to left half
            else
                low = mid + 1; // go to right half
        }
        // right half is sorted
        else
        {
            if (target > nums[mid] && target <= nums[high]) // target >= nums[mid] is not required because equality has already been checked earlier
                low = mid + 1;                              // go to right half
            else
                high = mid - 1; // go to left half
        }
    }

    // if element not found
    return -1;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {6, 7, 1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << search(arr, size, 7);
}

/*
    * No matter how many times the array's rotated,
    * One half of array will always be sorted
    * eg:
    * [1,2,3,4,5,6,7] l < m < h => all sorted
    * [7,1,2,3,4,5,6] l !< m, but m < h => right half sorted
    * [6,7,1,2,3,4,5] l !< m, but m < h => right half sorted
    * [5,6,7,1,2,3,4] l !< m, but m < h => right half sorted
    * [4,5,6,7,1,2,3] l < m and m !< h => left half sorted
    * [3,4,5,6,7,1,2] l < m and m !< h => left half sorted
    * [2,3,4,5,6,7,1] l < m and m !< h => left half sorted
    * 
    * similarly:
    * [1,2,3,4,5,6] l < m < h => all sorted
    * [6,1,2,3,4,5] l !< m but, m < h => right half sorted
    * [5,6,1,2,3,4] l !< m but, m < h => right half sorted
    * [4,5,6,1,2,3] l < m and m !< h => left half sorted
    * [3,4,5,6,1,2] l < m and m !< h => left half sorted
    * [2,3,4,5,6,1] l < m and m !< h => left half sorted
    * https://bit.ly/3h63lwo
*/