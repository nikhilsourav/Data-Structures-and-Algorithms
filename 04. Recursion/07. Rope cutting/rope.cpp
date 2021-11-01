/*
    Given a rope of length n. Cut this rope into maximum number of pieces such that
    every piece has length as either a, b or c
*/

#include <bits/stdc++.h>
using namespace std;

// Find max rope length
int rope(int n, int a, int b, int c)
{
    // base case
    if (n == 0)
        return 0;
    if (n < 0)
        return -1;

    // max value of three functions
    int max = (rope(n - a, a, b, c) > rope(n - b, a, b, c)) ? (rope(n - a, a, b, c) > rope(n - c, a, b, c) ? rope(n - a, a, b, c) : rope(n - c, a, b, c)) : (rope(n - b, a, b, c) > rope(n - c, a, b, c) ? rope(n - b, a, b, c) : rope(n - c, a, b, c));

    // if all three of them return -1
    if (max == -1)
        return -1;

    // return answer
    return max + 1;
}

// Driver code
int main()
{
    // Given numbers
    int n = 9, a = 2, b = 2, c = 2;

    // fn call
    cout << rope(n, a, b, c);
}
