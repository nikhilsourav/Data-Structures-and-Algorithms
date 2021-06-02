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
    cout << power(3, 2);
}