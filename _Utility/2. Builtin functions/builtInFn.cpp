// https://www.geeksforgeeks.org/builtin-functions-gcc-compiler/

#include <bits/stdc++.h>
using namespace std;
#define print cout <<

// Driver cdoe
int main()
{
    // return no of set bit in an int
    int num1 = 7;
    __builtin_popcount(num1);
    long num2 = 6;
    __builtin_popcountl(num2);
    long long num3 = 8;
    __builtin_popcountll(num3);

    // return true if num has odd set bit oterwise false
    int num4 = 8;
    __builtin_parity(num4);
    long num5 = 6;
    __builtin_parityl(num5);
    long long num6 = 3;
    __builtin_parityll(num6);

    // count leading zeroes in binary of an integer
    int num7 = 16;
    __builtin_clz(num7);
    long num8 = 11;
    __builtin_clzl(num8);
    long long num9 = 32;
    __builtin_clz(num9);

    // find minimum of x numbers
    int num10 = 2, num11 = 3, num12 = 1, num13 = 9;
    print min({num10, num11, num12, num13});

    // find gcd of two numbers
    int num14 = 4, num15 = 6;
    print __gcd(num14, num15);
}