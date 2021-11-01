/*
    Check whether a number is prime or not
    eg: 7 is prime 9 is not
*/

#include <bits/stdc++.h>
#define LL unsigned long long int
using namespace std;

// =============== Method one O(n) ================= //
bool checkPrime_MethodOne(LL number)
{
    // base case
    if (number <= 1)
        return false;

    // logic:
    int count = 0;
    for (int i = 1; i <= number; i++)
        if (number % i == 0)
            count++;

    // return ans
    if (count == 2)
        return true;
    return false;
}

// =============== Method two O(n/2) ================= //
bool checkPrime_MethodTwo(LL number)
{
    // base case
    if (number <= 1)
        return false;

    // logic:
    bool flag = 1;
    for (int i = 2; i <= number / 2; i++)
        if (number % i == 0)
            return false;

    // return ans
    return true;
}

// =============== Method three O(sqrt(n)) ================= //
bool checkPrime_MethodThree(LL number)
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

// Best method (for very large number like 10092003300140014003) //
bool checkPrimeEfficiently(LL number)
{
    if (number == 1)
        return false;

    if (number == 2 || number == 3)
        return true;

    if (number % 2 == 0 || number % 3 == 0)
        return false;

    for (int i = 5; i * i <= number; i = i + 6)
        if (number % i == 0 || number % (i + 2) == 0)
            return false;

    return true;
}

// Driver code
int main()
{
    // Given number
    LL num = 10092003300140014003;

    // fn call
    cout << checkPrimeEfficiently(num) << "\n";
}

/*
    NOTES:
    * Main idea of square root method: if we find a divisor below sqrt(n) it's not prime.
    * Even if n has a divisor > sqrt(n) we don't need to check it as it's pair must've already been found.
    * Note that every prime number can be represented as 6n+1 or 6n-1 except 2 and 3
    * 2 and 3 are only two consecutive prime
    * https://www.youtube.com/watch?v=T0XbxCYLBmc *8:00
*/