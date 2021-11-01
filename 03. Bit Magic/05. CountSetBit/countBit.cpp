/*
    Count total number of set (1) bit in binary representation of a number
    eg: 15 (decimal) => 1111 (binary) => total set bit = 4
*/

#include <bits/stdc++.h>
using namespace std;

// Count set bits Brian Kerningam's algorithm
// Logic: (n & n-1) strikes off (deletes) last set bit
// Time complexity : O(set bit count)
int countSetBit(int n)
{
    // init vars
    int count = 0;

    // logic:
    while (n)
    {
        // first iteration: 101 & 100 = 100 // second iteration:  100 & 011 = 0
        n &= (n - 1);
        count++;
    }

    // answer
    return count;
}

// Driver code
int main()
{
    // Given number
    int num = 5;

    // fn call
    cout << countSetBit(num);
}