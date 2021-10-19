#include <iostream>
using namespace std;

#define LL long long
const LL MOD = 1000000007;

// remember: (x + y) % mod = (x % mod + y % mod) % mod
// O(log (y))
LL fastModuloExponent(LL x, LL y, LL MOD)
{
    // init result
    LL result = 1;

    // bit masking
    while (y > 0)
    {
        // if last bit is 1
        if (y & 1)
            result = (result * x) % MOD;

        // square of x
        x = (x * x) % MOD;

        // discard rightmost bit
        y = y >> 1;
    }

    // answer
    return result;
}

// Driver code
int main()
{
    cout << fastModuloExponent(3, 5, MOD);
}

/*
    * Calculate 3 ^ 5
    * initialize result = 1
    * Convert 5 to binary = 1 0 1
    * multiply each bit to successive square of 3 
    * {(3^2^2 * 1)} * { (3^2 * 0)_skippded_ } * {(3^1 * 1)} = 243
*/