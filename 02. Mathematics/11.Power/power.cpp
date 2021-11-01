/*
    Calculate base to the power exponent
    eg: base = 2, expo = 3 then power = 2^3 = 8
*/

#include <bits/stdc++.h>
using namespace std;

/*
    power (x,n) can be written as :

    power(x,n/2) * power(x,n/2) // if n is even

    power(x,n-1)*x // if n is odd
*/

// Time complexity O(log n)
int power(int x, int n)
{
    // base case
    if (n == 0)
        return 1;

    // init vars:
    int temp = power(x, n / 2);
    temp *= temp;

    // logic:
    if (n % 2 == 0)
        return temp;
    else
        return temp * x;
}

// Driver code
int main()
{
    // Given numbers
    int base = 3, expo = 2;

    // fn call
    cout << power(base, expo);
}