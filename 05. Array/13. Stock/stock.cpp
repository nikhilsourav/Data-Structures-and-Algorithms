/*
    Given stock prices for upcoming days. You can buy a stock in any day and
    sell the stock in any upcoming day. Maximize the profit.
    eg: [1,5,3,1,2,8]
    => buy on 1 sell on 5, profit = 4
    => buy on 1 sell on 8, profit = 7 {(2-1) + (8-2)}
    => total profit = 11
*/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity: O(n)
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
    int arr[] = {1, 5, 3, 1, 2, 8};
    int size = sizeof(arr) / sizeof(arr[0]);

    // fn call
    cout << maxProfit(arr, size);
}