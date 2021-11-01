/*
    Check if kth bit of a number is set (1) or not (0)
    eg: 10 (decimal input) => 001010 (binary): check 4th bit => 4th bit is set
*/

#include <bits/stdc++.h>
using namespace std;

// Check kth bit
bool checkSetBitWithLeftShift(int n, int k)
{
    // 101 & ( 001 << (3-1) ) = 101 & 100 = 4 (non zero)
    if ((n & (1 << (k - 1))) != 0)
        return true;

    // answer
    return false;
}

// Same concept, but with right shift
bool checkSetBitWithRightShift(int n, int k)
{
    // logic:
    if ((n >> (k - 1)) & 1 == 1)
        return true;

    // answer
    return false;
}

// Driver code
int main()
{
    // Given numbers
    int num1 = 10, num2 = 4;

    // fn call
    cout << checkSetBitWithLeftShift(num1, num2) << "\n";
    cout << checkSetBitWithRightShift(num1, num2) << "\n";
}