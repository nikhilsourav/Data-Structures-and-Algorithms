#include <bits/stdc++.h>
using namespace std;

// Iterative factorial Time complexity O(n) Better approach
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

// Recursive factorial Time complexity O(n)
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
    // fn call
    cout << factRecursive(6);
}