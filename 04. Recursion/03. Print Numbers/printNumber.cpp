/*
    Print number from 1 to N and N to 1 using recursion
*/

#include <bits/stdc++.h>
using namespace std;

// Head reursion (print 1 to N) Time complexity: O(n), Aux space: O(n)
void printNumbers(int n)
{
    // base case
    if (n == 0)
        return;

    // recursion
    printNumbers(n - 1);

    // print statement
    cout << n << " ";
}

// Tail recursion (print N to 1) Time complexity: O(n), Aux space: O(n)
void printNumbersInReverse(int n)
{
    // base case
    if (n == 0)
        return;

    // print statement
    cout << n << " ";

    // recursion
    printNumbersInReverse(n - 1);
}

// Driver code
int main()
{
    // Given number
    int num = 10;

    // print 1 to num
    printNumbers(num);
    cout << "\n";

    // print num to 1
    printNumbersInReverse(num);
}