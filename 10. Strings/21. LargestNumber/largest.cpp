/*
    Find largest number of n digits with given sum
    eg: sum = 12, n = 3 => 930
*/

#include <bits/stdc++.h>
using namespace std;

// Find largest number
string largestNumber(int n, int sum)
{
    // init string
    string output(n, '0');

    // logic:
    for (int i = 0; i < n; i++)
    {
        // init current max val
        int val = 0;

        // sum > 9
        if (sum > 9)
        {
            val = 9;
            sum -= 9;
        }

        // sum < 9
        else
        {
            val = sum;
            sum = 0;
        }

        // construct output string
        output[i] = val + '0';
    }

    // if sum has leftovers
    if (sum > 0)
        return "-1";

    // answer
    return output;
}

// Driver code
int main()
{
    // Given number
    int n = 5, sum = 12;

    // fn call
    cout << largestNumber(n, sum);
}