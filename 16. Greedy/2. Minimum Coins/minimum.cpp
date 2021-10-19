/*
    Given array of coins, find minimum number of coin
    which is equal to given amount such that all greater
    valued coins are included

    eg: 
        coins[] = {10, 5, 2, 1}
        amount 52
        sum = 5 * (10 rupee coin) + 1 * (2 rupee coin)
        Total coin = 6

    eg:
        coins[] = {9, 6, 5, 1}
        amount = 11
        sum = 1 * (9 rupee coin) + 2 * (1 rupee coin)
        Total coin = 3

        Note: 
        1 * (6 rupee coin) + 1 * (5 rupee coin) 
        is also possible which gives total coin = 2 but 
        in question we're asked to include higher value coins
*/
#include <bits/stdc++.h>
using namespace std;

// return min number of coins
int minCoins(int coin[], int n, int amount)
{
    // sort given array
    sort(coin, coin + n, greater<int>());

    // init result
    int res = 0;

    // logic:
    int i = 0, minim = INT_MAX;
    while (amount)
    {
        // if curr amount >= coin[i] store its multiple
        if (amount >= coin[i])
        {
            res += amount / coin[i];
            amount %= coin[i];
        }
        // otherwise check for next highest coin[i]
        else
            i++;

        // if at any point i == n, arrangement not possible
        if (i == n)
            return -1;
    }

    // return ans
    return res;
}

// Driver code
int main()
{
    // Given array
    int coin[] = {9, 6, 5, 1};
    int n = sizeof(coin) / sizeof(coin[0]);
    int amount = 11;

    // fn call
    cout << minCoins(coin, n, amount);
}

/*
    In the above problem, if coins[]
    has random values Greedy approach provides
    different result than expected

    consider:
    
        coins[] = {18, 1, 10}
        amount = 20

        ans based on above approach = 3 (18 + 1 + 1)
        actual ans = 2 (10 + 10)
*/