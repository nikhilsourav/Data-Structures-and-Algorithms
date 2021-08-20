/*
    program to show working of pointers.
    Print value and address of varialbes
    using single and double pointers
*/
#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // init var
    int x = 10;

    // declaration
    int *p1;  // p1 can store the address of variable x
    int **p2; // p2 can store address of p1 but not address of 'x'

    // initialization
    p1 = &x;
    p2 = &p1;

    // print address of x
    cout << (&x) << " " << (p1) << " " << (*p2) << "\n";

    // value of x
    cout << (x) << *(p1) << *(*p2) << "\n";
};