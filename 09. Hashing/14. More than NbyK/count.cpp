#include <bits/stdc++.h>
using namespace std;

// print elements with more than n/k occurance. Time: O(n), Space: O(n)
void printNbyK(int arr[], int n, int k)
{
    unordered_map<int, int> counter;
    for (int i = 0; i < n; i++)
        counter[arr[i]]++;

    for (auto val : counter)
        if (val.second > n / k)
            cout << val.first << " ";
}

// Driver code
int main()
{
    // Given array
    int arr[] = {10, 10, 20, 30, 20, 10, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    // fn call
    printNbyK(arr, n, k);
}