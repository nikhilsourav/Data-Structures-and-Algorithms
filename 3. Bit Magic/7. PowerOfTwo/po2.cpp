#include <bits/stdc++.h>
using namespace std;

// Assmption n>=0
bool powerOfTwo(int n)
{
    if (n == 0)
        return false;

    while (n != 1) // if at any point division gives odd num => not power of 2
    {
        if (n % 2 != 0)
            return false;
        n /= 2;
    }

    return true;
}

// best approach
bool towsPowerUsingBriansAlgorithm(int n)
{
    // return true if n != 0 and second condition :
    // unset the only set bit int n (fact) and if the number == 0 it's power of 2
    return (n != 0) && ((n & (n - 1)) == 0);
}

// Driver code
int main()
{
    int num = 16;
    cout << powerOfTwo(num) << "\n";
    cout << towsPowerUsingBriansAlgorithm(num) << "\n";
}

// powers of 2 has only one bit set