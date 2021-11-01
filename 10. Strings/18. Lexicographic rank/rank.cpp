/*
    Find lexicographic rank of a string
    eg: str = "BAC" => rank = 3

    "ABC"
    "ACB"
    "BAC" (answer)
    "BCA"
    "CAB"
    "CBA"
*/

#include <bits/stdc++.h>
using namespace std;

const int CHAR = 256;

// factorial of n
int fact(int n)
{
    return (n <= 1) ? 1 : n * fact(n - 1);
}

// Find rank
int lexicographicRank(string &str)
{
    // init result
    int res = 1;

    // init size
    int n = str.size();

    // factorial of str.size()
    int factorial = fact(n);

    // init count array
    int count[CHAR] = {0};

    // logic:
    for (int i = 0; i < n; i++)
        count[str[i]]++;

    for (int i = 1; i < CHAR; i++)
        count[i] += count[i - 1];

    for (int i = 0; i < n - 1; i++)
    {
        factorial = factorial / (n - i);
        res = res + count[str[i] - 1] * factorial;

        for (int j = str[i]; j < CHAR; j++)
            count[j]--;
    }

    // return answer
    return res;
}

int main()
{
    // Given string
    string str = "STRING";

    // fn call
    cout << lexicographicRank(str);
}