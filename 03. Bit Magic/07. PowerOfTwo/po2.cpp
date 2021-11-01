/*
    Check if a number is power of 2 or not
    eg: 64 => true
*/

#include <bits/stdc++.h>
using namespace std;

// Assmption n>=0
bool powerOfTwo(int n)
{
    // corner case
    if (n == 0)
        return false;

    // logic: if at any point division gives odd num => not power of 2
    while (n != 1)
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }

    // answer
    return true;
}

// Best approach
bool towsPowerUsingBriansAlgorithm(int n)
{
    // (n != 0) and (unset the only set bit and check if the number == 0)
    return (n != 0) && ((n & (n - 1)) == 0);
}

// Driver code
int main()
{
    // Given number
    int num = 16;

    // fn call
    cout << powerOfTwo(num) << "\n";
    cout << towsPowerUsingBriansAlgorithm(num) << "\n";
}

/*
    NOTE: Power of two has only one bit set
*/