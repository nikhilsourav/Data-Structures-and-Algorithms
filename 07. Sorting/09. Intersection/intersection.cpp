/*
    Given two sorted array. Print their intersection.
    eg: a1[] = [1,2,3,4,5], a2[] = [1,2,3];
    intersection = [1,2,3]
*/

#include <bits/stdc++.h>
using namespace std;

// Function to return a list containing the intersection of the two arrays.
vector<int> printIntersection(int arr1[], int arr2[], int N, int M)
{
    // sort
    sort(arr1, arr1 + N);
    sort(arr2, arr2 + M);

    // initialize variables:
    vector<int> answer;
    int i = 0, j = 0;

    // logic:
    while (i < N && j < M)
    {
        // handle duplicates
        if (i > 0 && arr1[i] == arr1[i - 1])
        {
            i++;
            continue;
        }

        // intersection logic:
        if (arr1[i] < arr2[j])
            i++;
        else if (arr1[i] > arr2[j])
            j++;
        else
        {
            answer.push_back(arr1[i]);
            i++;
            j++;
        }
    }

    // answer
    return answer;
}

// Driver code
int main()
{
    // Given array
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {2, 4, 6, 7, 8};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(arr2) / sizeof(arr2[0]);

    // Output
    vector<int> answer = printIntersection(arr1, arr2, n, m);
    for (auto x : answer)
        cout << x << " ";
}