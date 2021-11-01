/*
    Max of all subarray of size k
*/

#include<bits/stdc++.h>
using namespace std;

// Max of all subarray
void printMax(int arr[], int n, int k)
{
    // create a deque
    deque<int> dq;

    // initialize deque
    for (int i = 0; i < k; ++i)
    {

        while (!dq.empty() && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // logic:
    for (int i = k; i < n; ++i)
    {

        cout << arr[dq.front()] << " ";

        while ((!dq.empty()) && dq.front() <= i - k)
            dq.pop_front();

        while ((!dq.empty()) && arr[i] >= arr[dq.back()])
            dq.pop_back();

        dq.push_back(i);
    }

    // print max
    cout << arr[dq.front()];
}

// Driver code
int main()
{
    // Given array
    int arr[] = {20, 40, 30, 10, 60};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    // fn call
    printMax(arr, n, k);
}