/*
    Find Least Common Multiple of two integers
    eg: LCM(7,3) = 21
*/

#include <bits/stdc++.h>
using namespace std;

// Similar to GCD O(a*b - max(a,b))
int getLCM(int x, int y)
{
    // init vars
    int LCM = max(x, y);

    // logic:
    while (1)
    {
        if (LCM % x == 0 && LCM % y == 0)
            return LCM;
        LCM++;
    }

    // return ans
    return LCM;
}

// Effeicient solution
int getGCD(int a, int b)
{
    // base case
    if (b == 0)
        return a;

    // recursion
    else
        return getGCD(b, a % b);
}
int getLCMefficiently(int x, int y)
{
    return (x * y) / getGCD(x, y);
}

// Driver code
int main()
{
    // Given numbers
    int a = 7, b = 3;

    // fn call
    cout << getLCMefficiently(a, b) << "\n";
}

/*
    NOTES:
    * gcd(a,b) * lcm(a,b) = (a*b)
    * https://www.youtube.com/watch?v=VWOUh4w_zVI 3:20
*/