#include <bits/stdc++.h>
using namespace std;

// Naive solution
void printDivisors(int n)
{
    for (int i = 1; i <= n; i++)
        if (n % i == 0)
            cout << i << " ";
}

// best solution
void printDivisorEfficiently(int n)
{

    // logic:
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if (i != n / i) // for perfect squares, to prevent printing twice
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