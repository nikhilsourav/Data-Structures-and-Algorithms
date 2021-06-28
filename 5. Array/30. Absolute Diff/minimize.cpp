// CPP program to Minimize the absolute difference of sum of two subsets
// https://www.geeksforgeeks.org/minimize-absolute-difference-sum-two-subsets/

#include <bits/stdc++.h>
using namespace std;

// function to print difference
void subsetDifference(int n)
{
    // summation of n elements
    int s = n * (n + 1) / 2;

    // if divisible by 4
    if (n % 4 == 0)
    {
        cout << "First subset sum = " << s / 2 << "\n";
        cout << "Second subset sum = " << s / 2 << "\n";
        cout << "Difference = " << 0 << "\n";
    }
    else if (n % 4 == 1 || n % 4 == 2)
    {

        cout << "First subset sum = " << s / 2 << "\n";
        cout << "Second subset sum = " << s / 2 + 1 << "\n";
        cout << "Difference = " << 1 << "\n";
    }
    else // if n % 4 == 3
    {
        cout << "First subset sum = " << s / 2 << "\n";
        cout << "Second subset sum = " << s / 2 << "\n";
        cout << "Difference = " << 0 << "\n";
    }
}

// Driver code
int main()
{
    int t;
    cout << "Number of testcases : ";
    cin >> t;
    while (t--)
    {
        int n;
        cout << "Enter number : ";
        cin >> n;
        subsetDifference(n);
    }
    return 0;
}
