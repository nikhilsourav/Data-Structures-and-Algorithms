#include <bits/stdc++.h>
using namespace std;

// Naive approach to GCD O(min(x,y))
int getGCD(int x, int y)
{
    // get min of given two numbers
    int GCD = min(x, y);

    // if min divides both x and y break and thats the ans otherwise decrease and try again
    while (GCD)
    {
        if (x % GCD == 0 && y % GCD == 0)
            break;
        GCD--;
    }

    // return answer
    return GCD;
}

// Better approach Euclidean algorithm
int euclidAlgorithm(int x, int y)
{
    // logic:
    while (x != y)
    {
        if (x > y)
            x -= y;
        else
            y -= x;
    }

    // return ans;
    return x;
}

// Best approach optimized Euclidean algorithm
int optimizedEuclid(int a, int b)
{
    if (b == 0)
        return a;
    else
        return optimizedEuclid(b, a % b);
}

// Driver code
int main()
{
    // Given numbers
    int a = 4, b = 6;

    // fn call
    cout << optimizedEuclid(a, b) << "\n";
}

/*
    NOTES:
    * gcd(a,b) * lcm(a,b) = (a*b)
    * https://www.youtube.com/watch?v=VWOUh4w_zVI 3:20
*/