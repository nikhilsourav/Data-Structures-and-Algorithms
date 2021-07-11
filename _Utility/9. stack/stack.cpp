#include <bits/stdc++.h>
using namespace std;

// Driver code
int main()
{
    // internally, stack is implemented using deque container
    stack<int> stk;

    // =========== push ============= //
    stk.push(10); // push element
    stk.push(20); // push element
    stk.push(30); // push element
    stk.push(40); // push element
    stk.push(50); // push element
    stk.push(60); // push element

    // =========== pop ============= //
    stk.pop();

    // =========== top ============= //
    int x = stk.top();
    cout << "top element:" << x << "\n";

    // =========== size ============= //
    int sz = stk.size();
    cout << "size " << sz << "\n";

    // =========== empty ============= //
    bool isEmpty = stk.empty();
    cout << "is stack empty " << boolalpha << isEmpty << "\n";

    // =========== print =============//
    cout << "Stack elements: ";
    int stackSize = stk.size();
    for (int i = 0; i < stackSize; i++)
    {
        cout << stk.top() << " ";
        stk.pop();
    }
}