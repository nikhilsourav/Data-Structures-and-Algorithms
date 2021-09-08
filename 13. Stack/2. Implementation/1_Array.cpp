#include <bits/stdc++.h>
using namespace std;

// array implementation of stack
struct MyStack
{
    // init dynamic arr
    int *arr;
    int cap;
    int top;

    // constructor to init stack
    MyStack(int c)
    {
        cap = c;
        arr = new int[cap];
        top = -1;
    }

    // push method
    void push(int x)
    {
        if (top == cap - 1)
        {
            cout << "Stack is full" << endl;
            return;
        }
        top++;
        arr[top] = x;
    }

    // pop method
    int pop()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        int res = arr[top];
        top--;
        return res;
    }

    // check first element
    int peek()
    {
        if (top == -1)
        {
            cout << "Stack is Empty" << endl;
            return INT_MIN;
        }
        return arr[top];
    }

    // stack size
    int size()
    {
        return (top + 1);
    }

    // check if stack is empty
    bool isEmpty()
    {
        return top == -1;
    }
};

// Driver code
int main()
{
    // init stack
    MyStack s(5);

    // push values
    s.push(5);
    s.push(10);
    s.push(20);

    // methods
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.peek() << endl;
    cout << s.isEmpty() << endl;
}
