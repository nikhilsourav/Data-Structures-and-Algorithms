/*
    Find factorial of given number
    eg: 4! = 4 * 3 * 2 * 1 = 24
*/

#include <bits/stdc++.h>
using namespace std;

// Iterative factorial. Better approach, Time complexity O(n)
int factIterative(int n)
{
    // init vars
    int fact = 1;

    // logic:
    for (int i = n; i > 0; i--)
        fact = fact * i;

    // return ans
    return fact;
}

// Recursive factorial. Time complexity O(n)
int factRecursive(int n)
{
    // base case
    if (n == 0)
        return 1;

    // recursive call
    return n * factRecursive(n - 1);
}

// Driver code
int main()
{
    // Given number
    int num = 6;

    // fn call
    cout << factRecursive(num);
}