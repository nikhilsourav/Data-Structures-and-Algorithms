/*
    Print frequency of each element of an array using hashing
    eg [1,1,1,2,2,2,2,2] => 1:3, 2:5
*/

#include <bits/stdc++.h>
using namespace std;

// Print frequency
void printFrequency(int arr[], int n)
{
    // initialize map
    unordered_map<int, int> frequency;

    // logic:
    for (int i = 0; i < n; i++)
        frequency[arr[i]]++;

    // print Method 1
    cout << "Method 1:\n";
    for (int i = 0; i < frequency.size(); i++)
        if (frequency[i])
            cout << i << ": " << frequency[i] << "\n";

    // print Method 2
    cout << "\nMethod 2:\n";
    for (auto val : frequency)
        if (val.second)
            cout << val.first << ": " << val.second << "\n";
}

// Driver code
int main()
{
    // Given array
    int arr[] = {1, 1, 1, 2, 3, 3, 4, 5, 1, 1, 2, 3, 4, 4, 9, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    // fn call
    printFrequency(arr, n);
}