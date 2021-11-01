/*
    Given a sorted array and a sum. Find if there is a pair with given sum
*/
#include <bits/stdc++.h>
using namespace std;

// Find first sum pair in O(n) time
pair<int, int> findPair(int arr[], int size, int sum)
{
    // low and high vars for two pointer
    int low = 0, high = size - 1;

    // logic:
    while (low <= high)
    {
        // calculate curent sum and store it
        int currSum = arr[low] + arr[high];

        // if current sum = given sum , print the pair
        if (currSum == sum)
            return make_pair(arr[low], arr[high]);

        // if currSum > sum, reduce high
        else if (currSum > sum)
            high -= 1;

        // otherwise increase low
        else
            low += 1;
    }

    // if no pair found
    return make_pair(-1, -1);
}

// Driver code
int main()
{
    // Given array
    int arr[] = {2, 3, 4, 9, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    int sum = 20;

    // fn call
    pair<int, int> p1 = findPair(arr, size, sum);
    cout << p1.first << " " << p1.second;
}