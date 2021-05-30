#include <bits/stdc++.h>
using namespace std;

// similar to GCD O(a*b - max(a,b))
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

// effeicient solution
int getGCD(int a, int b)
{
    if (b == 0)
        return a;
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
    int a = 7, b = 3;
    cout << getLCMefficiently(a, b) << "\n";
}

/*
    NOTES:
    * gcd(a,b) * lcm(a,b) = (a*b)
    * https://www.youtube.com/watch?v=VWOUh4w_zVI 3:20
*/