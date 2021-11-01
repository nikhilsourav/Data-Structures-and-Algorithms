/*
    Count distinct elements after union of two array
    eg a1 = [1,2,3], a2 = [2,3,4] = [1,2,3] => distinct elements = 3
*/

#include <bits/stdc++.h>
using namespace std;

// Count
int countDistinct(int arr1[], int n1, int arr2[], int n2)
{
    // init set
    unordered_set<int> counter(arr1, arr1 + n1);

    // insert all element of arr2
    for (int i = 0; i < n2; i++)
        counter.insert(arr2[i]);

    // result
    return counter.size();
}

// Driver code
int main()
{
    // Given array
    int arr1[] = {10, 15, 20, 5, 30};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int arr2[] = {30, 5, 30, 80};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);

    // fn call
    cout << countDistinct(arr1, n1, arr2, n2);
}