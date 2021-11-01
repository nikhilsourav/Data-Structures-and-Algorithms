#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // Given number
    int num = 57.86;

    // Init pointer
    int *ptr = &num;

    // Size of int for this compiler
    cout << "Integer size: " << sizeof(int) << "\n"; // 8

    // Print ptr, ptr + 1 and ptr -1
    cout << "Address ptr is " << ptr << "\n";         // 2014
    cout << "Address ptr + 1 is " << ptr + 1 << "\n"; // 2010
    cout << "Address ptr - 1 is " << ptr - 1 << "\n"; // 2010

    // ptr + 1 and ptr - 1 contains garbage value
    // as we didn't initialize their values
    cout << "\nValue of *ptr is " << *ptr << "\n";
    cout << "Value of *(ptr + 1) is " << *(ptr + 1) << "\n";
    cout << "Value of *(ptr - 1) is " << *(ptr - 1) << "\n";
}