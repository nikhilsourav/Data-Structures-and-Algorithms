/*
    Given two numbers M and N. The task is to find the position of the
    rightmost different bit in the binary representation of numbers.
    eg: 11, 15 (decimal input) => 1011, 1111 (binary) => 3rd bit is rightmost different bit
*/

#include <bits/stdc++.h>
using namespace std;

// Check kth bit is set or not
bool checkSetBit(int n, int k)
{
    // logic:
    if ((n & (1 << (k - 1))) != 0)
        return true;

    // fn call
    return false;
}

// Driver code
int main()
{
    // Input
    int A, B, i;
    cin >> A >> B;

    // Compare all number one by one, loop for 64 times for 64 bit compiler
    for (i = 1; i <= 64; i++)
        if (checkSetBit(A, i) != checkSetBit(B, i))
            break;

    // Output
    cout << i << " ";
}