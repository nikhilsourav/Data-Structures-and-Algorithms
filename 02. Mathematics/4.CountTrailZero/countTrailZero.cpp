#include <bits/stdc++.h>
using namespace std;

// count zero after finding factorial (overflow even at small numbers)
int countZeros(int n)
{
    // find factorial
    int fact = 1;
    for (int i = n; i > 0; i--)
        fact *= i;

    // count trailing zeros
    int countZeros = 0;
    while (fact % 10 == 0)
    {
        countZeros++;
        fact /= 10;
    }

    // return ans
    return countZeros;
}

// efficient way O(log n)
int countZerosEfficiently(int n)
{
    // init var
    int count = 0;

    // logic:
    for (int i = 5; i <= n; i *= 5) // count 2 and 5 which are the reason for trailing zeros
        count += n / i;             // sum of floor of n/i

    // answer
    return count;
}

// Driver code
int main()
{
    // Given number
    int num = 10;

    // fn call
    cout << "counted efficiently: " << countZerosEfficiently(num) << "\n";
}

/*
    NOTES:
    * The number of 5's are always less than the number of 2's in a factorial
    * Every 5th number is going to have 5 as a prime factor
    * For a number n, it will have [n/5] 5's in prime factor where [] is floor fn
    * A table of factorials: https://www.mymathtables.com/numbers/100-factorial-tables-chart.html
    * Explanation: https://www.youtube.com/watch?v=fx8rUY_iIms
*/