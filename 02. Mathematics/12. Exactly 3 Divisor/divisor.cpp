/*
    Given a number, find whether it has exactly 3 divisors or not.
*/

#include <bits/stdc++.h>
using namespace std;

// check whether number is prime
bool isPrime(int number)
{
    // logic
    for (int i = 2; i * i <= number; i++)
        if (number % i == 0)
            return false;

    // answer
    return true;
}

// check wheter number has exactly 3 divisors
int exactly3Divisors(int number)
{
    // init vars:
    int count = 1;

    // base case
    if (number <= 3)
        return 0;

    // only those number whose sqrt is prime have exactly 3 divisor
    for (int i = 3; i <= sqrt(number); i++)
        if (isPrime(i) && (i * i) <= number)
            count++;

    // return ans
    return count;
}

// Driver code
int main()
{
    // Given number
    int num = 8219;
    cout << exactly3Divisors(num);
}