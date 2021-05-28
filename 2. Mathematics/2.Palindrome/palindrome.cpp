#include <bits/stdc++.h>
using namespace std;

// Time complexity O(digit)
bool checkPalindrome(int number)
{
    // init vars
    int temp = number, remainder, reversed = 0;

    // logic:
    while (number)
    {
        remainder = number % 10;
        reversed = reversed * 10 + remainder;
        number /= 10;
    }

    // return ans
    return temp == reversed;
}

// Driver code
int main()
{
    // given number
    int num = 121;

    // output
    checkPalindrome(num) ? cout << "Palindrome" : cout << "Not a palindrome";
}