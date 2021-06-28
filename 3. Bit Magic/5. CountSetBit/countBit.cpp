#include <bits/stdc++.h>
using namespace std;

// count set (1) bits Brian Kerningam's algorithm
// logic: (n & n-1) strikes off (deletes) last set bit
// Time complexity : O(set bit count)
int countSetBit(int n)
{
    // init vars
    int count = 0;

    // logic
    while (n)
    {
        n &= (n - 1); // first iteration: 101 & 100 = 100 // second iteration:  100 & 011 = 0
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