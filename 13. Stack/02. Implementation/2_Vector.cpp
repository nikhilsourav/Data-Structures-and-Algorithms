#include <bits/stdc++.h>
using namespace std;

// Vector implementation of stack
struct MyStack
{
    // init vector
    vector<int> v;

    // push operation
    void push(int x)
    {
        v.push_back(x);
    }

    // pop operation
    int pop()
    {
        int res = v.back();
        v.pop_back();
        return res;
    }

    // last element in stack
    int peek()
    {
        return v.back();
    }

    // stack size
    int size()
    {
        return v.size();
    }

    // check if stack is empty
    bool isEmpty()
    {
        return v.empty();
    }
};

// Driver code
int main()
{
    // Init stack
    MyStack s;

    // Push 3 element
    s.push(5);
    s.push(10);
    s.push(20);

    // Stack methods
    cout << s.pop() << "\n";
    cout << s.size() << "\n";
    cout << s.peek() << "\n";
    cout << s.isEmpty() << "\n";
}
