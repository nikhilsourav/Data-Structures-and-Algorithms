#include <bits/stdc++.h>
using namespace std;

// maximize profit
int maxProfit(int *arr, int size)
{
    // init vars:
    int profit = 0;

    // if price going down => ignore, if price going up sum
    for (int i = 1; i < size; i++)
        if (arr[i] > arr[i - 1])
            profit += (arr[i] - arr[i - 1]);

    // answer
    return profit;
}

// Driver code
int main()
{
    // Given array
    int size = 6;
    int arr[size] = {1, 5, 3, 1, 2, 8};

    // fn call
    cout << maxProfit(arr, size);
}