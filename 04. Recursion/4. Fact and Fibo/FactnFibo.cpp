#include <bits/stdc++.h>
using namespace std;

// factorial
int fact(int n)
{
    // base case
    if (n == 0)
        return 1;

    // fn call
    return n * fact(n - 1);
}

// fibonacci
int fib(int n)
{
    // base case
    if (n == 0) // if (n<=1) return n
        return 0;
    if (n == 1)
        return 1;

    // fn call
    return (fib(n - 1) + fib(n - 2));
}

// Driver code
int main()
{
    // Given number
    int num = 9;

    // fn call
    cout << fact(num) << "\n";
    cout << fib(num) << "\n";
}