/*
    Find longest consecutive ones
    eg: [1,1,1,0,0,1,1,0,1] => 3
*/

#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
int countOnes(int arr[], int size)
{
    // init vars
    int result = 0, currentCount = 0;

    // logic:
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == 0)
            currentCount = 0;
        else
        {
            currentCount++;
            result = max(result, currentCount);
        }
    }

    // answer
    return result;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << countOnes(arr, size) << "\n";
}