/*
    Given an array of n numbers that has values in range [1, n+1]. Every no. appear exactly once.
    Hence one number is missing. Find the missing number
    
    Properties of XOR:
    x^x = 0
    x^0 = x
    x^y = y^x
    x^(y^z) = (x^y)^x
*/
#include <bits/stdc++.h>
using namespace std;

// O(n)
int findNumber(int arr[], int n)
{
    // init variable
    int found = 0;

    for (int i = 0; i < n; i++) // XOR of all number in array
        found ^= arr[i];

    for (int i = 1; i <= n + 1; i++) // XOR of all number from 1 to n+1
        found ^= i;

    // answer
    return found;
}

// Driver code
int main()
{
    int arr[] = {1, 4, 3, 2};
    cout << findNumber(arr, 4);
}