#include <bits/stdc++.h>
using namespace std;

// count number of distinct elements
int countDistinct(int arr[], int n)
{
    // initialize set and insert all element
    unordered_set<int> count(arr, arr + n);

    // size represent number of distinct elements
    return count.size();
}
// Driver code
int main()
{
    // Given array
    int arr[] = {1, 1, 1, 2, 3, 3, 4, 5, 1, 1, 2, 3, 4, 4, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << countDistinct(arr, n);
}