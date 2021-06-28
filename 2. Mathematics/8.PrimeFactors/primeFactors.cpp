#include <bits/stdc++.h>
using namespace std;

// Naive solution O(n2 * log n)
bool isPrime(int number)
{
    // corner case
    if (number == 1)
        return false;

    // logic:
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;

    // answer
    return true;
}

void primeFactorNaive(int n)
{
    for (int i = 2; i < n; i++)
    {
        if (isPrime(i))
        {
            // if prime check for number of factors to next power
            int x = i;
            while (n % x == 0) // first check 2 then 2^2 etc
            {
                cout << i << " ";
                x *= i;
            }
        }
    }
}

// better solution
void primeFactorEfficient(int n)
{
    if (n <= 1)
        return;

    for (int i = 2; i * i <= n; i++) // if i is a factor
        while (n % i == 0)           // repeatedly divide by i
        {
            cout << i << " ";
            n /= i;
        }

    if (n > 1) // if n was prime or a number after division is left, it's explicitly printed
        cout << n << " ";
}

// best solution
void printFactorOptimized(int n)
{
    if (n <= 1)
        return;

    // check explicitly for 2
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n /= 2;
    }
    // check explicitly for 3
    while (n % 3 == 0)
    {
        cout << 3 << " ";
        n /= 3;
    }

    // check for 5, 7 and thier multiples
    for (int i = 5; i * i <= n; i += 6)
    {
        while (n % i == 0)
        {
            cout << i << " ";
            n /= i;
        }
        while (n % (i + 2) == 0)
        {
            cout << (i + 2) << " ";
            n /= (i + 2);
        }
    }

    // if remaining n is prime explicitly print n
    if (n > 3)
        cout << n;
}

// Driver code
int main()
{
    // Given number
    int n = 227;

    // fn call
    primeFactorEfficient(n);
}