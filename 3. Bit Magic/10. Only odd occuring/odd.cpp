/*  
    Given an array of int where all no. appear even number of times except one no. find it
    Properties of XOR:
    x^x = 0
    x^0 = x
    x^y = y^x
    x^(y^z) = (x^y)^x
*/

#include <bits/stdc++.h>
using namespace std;

// O(n)
int findOddOccurance(int arr[], int n)
{
    // init vars
    int found = 0;

    // logic:
    for (int i = 0; i < n; i++)
        found ^= arr[i];

    // answer
    return found;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {4, 2, 4, 4, 5, 5, 4, 3, 2};

    // fn call
    cout << findOddOccurance(arr, 9);
}