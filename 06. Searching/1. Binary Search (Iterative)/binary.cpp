#include <bits/stdc++.h>
using namespace std;

// binary search iterative
int binarySearch(int arr[], int size, int element)
{
    // init low and high
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        // initialize mid
        int mid = (low + high) / 2;

        // base case
        if (arr[mid] == element)
            return mid;

        // element greater than mid
        else if (arr[mid] < element)
            low = mid + 1;

        // element smaller than mid
        else
            high = mid - 1;
    }

    // if not found
    return -1;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int size = sizeof(arr) / sizeof(arr[0]);

    /* ============= binary search in array (return index) =============== */
    cout << "Binary search in array:" << binarySearch(arr, size, 80) << "\n";

    /* ============= binary search in vectors (return true or false) =============== */
    vector<int> vrr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    cout << "Binary search in vector: " << binary_search(vrr.begin(), vrr.end(), 9) << "\n";

    //  ================== initializing vector of integers ====================== //
    // for single occurrence
    vector<int> myVector_1 = {10, 15, 20, 25, 30, 35};

    // for multiple occurrences
    vector<int> myVector_2 = {10, 15, 20, 20, 25, 30, 35};

    // for no occurrence
    vector<int> myVector_3 = {10, 15, 25, 30, 35};

    // using lower_bound() to check if 20 exists
    // single occurrence
    // prints 2
    cout << "Position of 20 using lower_bound (in single occurrence): ";
    cout << lower_bound(myVector_1.begin(), myVector_1.end(), 20) - myVector_1.begin() << "\n";

    // using lower_bound() to check if 20 exists
    // multiple occurrence
    // prints 2
    cout << "The position of 20 using lower_bound (in multiple occurrence case) : ";
    cout << lower_bound(myVector_2.begin(), myVector_2.end(), 20) - myVector_2.begin() << "\n";

    // using lower_bound() to check if 20 exists
    // no occurrence
    // prints 2 ( index of next higher)
    cout << "The position of 20 using lower_bound (in no occurrence case) : ";
    cout << lower_bound(myVector_3.begin(), myVector_3.end(), 20) - myVector_3.begin() << "\n";
}