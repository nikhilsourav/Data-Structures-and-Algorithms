/*
    Print all divisors of given integer
    eg: 50 = [1, 2, 5, 10, 25, 50]
*/

#include <bits/stdc++.h>
using namespace std;

// Naive solution
void printDivisors(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << " ";
}

// Best solution
void printDivisorEfficiently(int n)
{

    // logic:
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            // for perfect squares, to prevent printing twice
            if (i != n / i)
                cout << n / i << " ";
        }
    }
}

// Driver code
int main()
{
    // Given number
    int n = 50;

    // fn call
    printDivisorEfficiently(n);
}