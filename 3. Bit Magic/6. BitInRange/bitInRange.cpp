/*
    Given a number N. Find the total count of set bits for all numbers from 1 to N (both inclusive)
*/

#include <bits/stdc++.h>
using namespace std;

// count set bit in range in O(log n)
int countSetBits(int n)
{
    if (n == 0)
        return 0;

    int x = floor(log10(n) / log10(2));
    return ((pow(2, x - 1) * x) + (n - pow(2, x) + 1) + countSetBits(n - pow(2, x)));
    // https://www.youtube.com/watch?v=g6OxU-hRGtY&t=6s
}
int main()
{
    int num = 4;
    cout << countSetBits(num);
}