/*
    Print prime number in given range L to R
    eg: L = 1, R = 25 => [2, 3, 5, 7, 11, 13, 17, 19, 23]
*/

#include <bits/stdc++.h>
using namespace std;

// To print prime from 1 to n. Time complexity O(n * sqrt n)
void sieveOfEratosthenes(int n)
{
    // init vars
    vector<bool> isPrime(n + 1, true);

    // logic:
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    // output
    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << " ";
    // https://www.youtube.com/watch?v=nDPo9hsDNvU
}

// Optimized sieveOfEratosthenes O(n loglog n)
void optimizedSieveOfEratosthenes(int n)
{
    // init vars
    vector<bool> isPrime(n + 1, true);

    // logic:
    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;
        }
    }
    // https://www.youtube.com/watch?v=eKp56OLhoQs
}

// Driver code
int main()
{
    // Given number
    int n = 100;

    // fn call
    sieveOfEratosthenes(n);
}