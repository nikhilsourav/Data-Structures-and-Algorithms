#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    int x = 5;
    int y = 3;
    unsigned temp = 5;
    int rs = 1;
    int ls = 2;
    cout << x << " & " << y << " is : " << (x & y) << "\n";                 // AND
    cout << x << " | " << y << " is : " << (x | y) << "\n";                 // OR
    cout << x << " ^ " << y << " is : " << (x ^ y) << "\n";                 // XOR
    cout << x << " >> " << rs << " is : " << (x >> rs) << "\n";             // right shift
    cout << x << " << " << ls << " is : " << (x << ls) << "\n";             // left shift
    cout << "~" << x << " is : " << (~x) << "\n";                           // operates in bit
    cout << "!" << x << " is : " << (!x) << "\n";                           // operates in number
    cout << "Negation of unsigned " << temp << " is : " << (~temp) << "\n"; // operates in bit
}