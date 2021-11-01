/*
    Rules: 

    1. Only one disc at a time
    2. No larger disc above smaller at any step
    3. Only the top disc of the tower can be moved

    For 1 disc
    * Move disc 1 from A to C
    
    For 2 discs
    * Move disc 1 from A to B
    * Move disc 2 from A to C
    * Move disc 1 from B to C
    
    For 3 discs
    * Move disc 1 from A to C
    * Move disc 2 from A to B
    * Move disc 1 from C to B
    * Move disc 3 from A to C
    * Move disc 1 from B to A
    * Move disc 2 from B to C
    * Move disc 1 from A to C
*/

#include <bits/stdc++.h>
using namespace std;

// Tower of Hanoi
void ToH(int n, char A, char B, char C)
{
    // base case
    if (n == 1)
    {
        cout << "Move 1 from " << A << " to " << C << endl;
        return;
    }

    // recursion
    ToH(n - 1, A, C, B);
    cout << "Move " << n << " from " << A << " to " << C << endl;
    ToH(n - 1, B, A, C);
}

// Driver code
int main()
{
    // Given number
    int num = 3;

    // fn call
    ToH(num, 'A', 'B', 'C');
}