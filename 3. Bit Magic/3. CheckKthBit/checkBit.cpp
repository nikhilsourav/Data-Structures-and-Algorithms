#include <bits/stdc++.h>
using namespace std;

// check if kth bit is set (1) or not (0)
bool checkSetBitWithLeftShift(int n, int k)
{
    // 101 & ( 001 << (3-1) ) = 101 & 100 = 4 (non zero)
    if ((n & (1 << (k - 1))) != 0)
        return true;

    return false;
}

// same concept, but with right shift
bool checkSetBitWithRightShift(int n, int k)
{
    if ((n >> (k - 1)) & 1 == 1)
        return true;

    return false;
}

// Driver code
int main()
{
    cout << checkSetBitWithLeftShift(9, 2) << "\n";
    cout << checkSetBitWithRightShift(9, 2) << "\n";
}