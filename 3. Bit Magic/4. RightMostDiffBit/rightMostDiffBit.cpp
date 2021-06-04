/*
    Given two numbers M and N. The task is to find the position of the 
    rightmost different bit in the binary representation of numbers.
*/
#include <bits/stdc++.h>
using namespace std;

// check kth bit is set or not
bool checkSetBit(int n, int k)
{
    if ((n & (1 << (k - 1))) != 0)
        return true;

    return false;
}

// Driver code
int main()
{
    // input
    int A, B, i;
    cin >> A >> B;

    // compare all number one by one
    for (i = 1; i <= 64; i++) // for 64 bit compiler
        if (checkSetBit(A, i) != checkSetBit(B, i))
            break;

    // output
    cout << i << " ";
}