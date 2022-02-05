/*
    Majority element is an element that appears more than n/2 times
    in an array of size n. return any index.
    eg: [6, 8, 4, 8, 8] => 8
*/

#include <bits/stdc++.h>
using namespace std;

// Time: O(n)
int majority(int arr[], int size)
{
    // check all elements if they occur more than n/2
    for (int i = 0; i < size; i++)
    {
        // init currentCount
        int count = 1;

        // increment count if found repeating element
        for (int j = i + 1; j < size; j++)
            if (arr[i] == arr[j])
                count++;

        // if at any point count > n/2 return i
        if (count > size / 2)
            return i;
    }

    // if not found
    return -1;
}

// Moore’s Voting Algorithm (might not give first index of occuring) Time: O(n)
int efficientMajority(int arr[], int n)
{
    // find a candidate
    int res = 0, count = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[res] == arr[i])
            count++;
        else
            count--;
        if (count == 0)
        {
            res = i;
            count = 1;
        }
    }

    // check whether candidate is majority
    count = 0;
    for (int i = 0; i < n; i++)
        if (arr[res] == arr[i])
            count++;
    if (count <= n / 2)
        res = -1;

    // answer
    return res;
}

// Driver code
int main()
{
    // Given array
    int arr[] = {6, 8, 4, 8, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << majority(arr, size) << "\n";
    cout << efficientMajority(arr, size) << "\n";
}