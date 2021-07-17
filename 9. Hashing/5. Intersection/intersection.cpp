#include <bits/stdc++.h>
using namespace std;

// Count distinct elements after intersection of two array
int countDistinct(int arr1[], int n1, int arr2[], int n2)
{
    // init map
    unordered_map<int, int> counter;

    // insert all elements and store their count
    for (int i = 0; i < n1; i++)
        counter[arr1[i]]++;
    for (int i = 0; i < n2; i++)
        counter[arr2[i]]++;

    // intersection counting logic:
    int count = 0;
    for (auto val : counter)
        if (val.second > 1)
            count++;

    // answer
    return count;
}

// Another optimized approach
int intersection(int arr1[], int n1, int arr2[], int n2)
{
    // init set with arr1
    unordered_set<int> counter(arr1, arr1 + n1);

    // if element of arr2 is already present, res++ and erase
    int res = 0;
    for (int i = 0; i < n2; i++)
    {
        if (counter.find(arr2[i]) != counter.end())
        {
            res++;
            counter.erase(arr2[i]);
        }
    }

    // answer
    return res;
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