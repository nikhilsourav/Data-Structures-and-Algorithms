#include <bits/stdc++.h>
using namespace std;

// To print prime from 1 to n. O(n * sqrt n)
void sieveOfEratosthenes(int n)
{
    // init vars
    vector<bool> isPrime(n + 1, true);

    // logic:
    for (int i = 2; i * i <= n; i++)
        if (isPrime[i])
            for (int j = i * i; j <= n; j += i)
                isPrime[j] = false;

    for (int i = 2; i <= n; i++)
        if (isPrime[i])
            cout << i << " ";
    // https://www.youtube.com/watch?v=nDPo9hsDNvU
}

// optimized sieveOfEratosthenes O(n loglog n)
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

int main()
{
    // Given number
    int n = 100;

    // fn call
    sieveOfEratosthenes(n);
}