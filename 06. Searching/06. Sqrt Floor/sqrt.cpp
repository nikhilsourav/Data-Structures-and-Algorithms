/*
    Given an integer, find floor of its square root.
    eg: 10 => 3
*/

#include <bits/stdc++.h>
using namespace std;

// Find square root
int binarySerach(int num)
{
    // int vars:
    int low = 1, high = num, ans = -1;

    // logic:
    while (low <= high)
    {
        // compute mid
        int mid = (low + high) / 2;

        // store current sq
        int mySqrt = (mid * mid);

        // if found
        if (mySqrt == num)
            return mid;

        // if greater
        else if (mySqrt > num)
            high = mid - 1;

        // save curr ans and look for higher value
        else
        {
            low = mid + 1;
            ans = mid;
        }
    }

    // answer
    return ans;
}

// Driver code
int main()
{
    // Given number
    int num = 27;

    // fn call
    cout << binarySerach(num);
}