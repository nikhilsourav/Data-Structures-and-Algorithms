/*
    Print value and address of variables using single and double pointers
*/

#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // Initialize variable
    int x = 10;

    // Declare inteer pointer
    int *p1;  // p1 can store the address of variable x
    int **p2; // p2 can store address of p1 but not address of 'x'

    // Initialize integer pointer
    p1 = &x;
    p2 = &p1;

    // Print address of x
    cout << (&x) << " " << (p1) << " " << (*p2) << "\n";

    // Value of x
    cout << (x) << *(p1) << *(*p2) << "\n";
};