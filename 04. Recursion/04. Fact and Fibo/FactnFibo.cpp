/*
    Find fibonacci(n) and factorial(n) using recursion.
    eg: fib(9) = 34, fact(9) = 362880 
*/

#include <bits/stdc++.h>
using namespace std;

// Factorial
int fact(int n)
{
    // base case
    if (n == 0)
        return 1;

    // fn call
    return n * fact(n - 1);
}

// Fibonacci
int fib(int n)
{
    // base case if (n<=1) return n
    if (n == 0)
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