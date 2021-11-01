#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // internally, stack is implemented using deque container
    stack<int> stk;

    // =========== PUSH ============= //
    stk.push(10); // push element
    stk.push(20); // push element
    stk.push(30); // push element
    stk.push(40); // push element
    stk.push(50); // push element
    stk.push(60); // push element

    // =========== POP ============= //
    stk.pop();

    // =========== TOP ============= //
    int x = stk.top();
    cout << "top element:" << x << "\n";

    // =========== SIZE ============= //
    int sz = stk.size();
    cout << "size " << sz << "\n";

    // =========== EMPTY ============= //
    bool isEmpty = stk.empty();
    cout << "is stack empty " << boolalpha << isEmpty << "\n";

    // =========== PRINT =============//
    cout << "Stack elements: ";
    int stackSize = stk.size();
    for (int i = 0; i < stackSize; i++)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}