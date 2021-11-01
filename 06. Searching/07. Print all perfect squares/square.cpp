/*
    Print all perfect squares from 1 to n
*/

#include <bits/stdc++.h>
using namespace std;
#define ll long long

// Using binary search to print all perfect square in range 1 to n, Time: O(log n)
bool checkPerfectSquare(ll num)
{
    // init vars
    ll low = 1, high = num, ans = -1;

    // logic:
    while (low <= high)
    {
        // compute mid
        ll mid = (low + high) / 2;

        // if mid * mid = num, mid is square root of num
        if (mid * mid == num)
            return mid;

        // otherwise go to left half
        else if (mid * mid > num)
            high = mid - 1;

        // if mid * mid < num, go for right half, meanwhile store this mid
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    // final check whether ans is square root of num
    if (ans * ans == num)
        return true;

    // if not return false
    return false;
}

// Driver code
int main()
{
    // Given num
    int num = 100;

    // Output
    for (ll i = 1; i <= num; i++)
        if (checkPerfectSquare(i))
            cout << i << " ";
}