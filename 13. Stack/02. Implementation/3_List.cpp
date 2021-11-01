#include <bits/stdc++.h>
using namespace std;

// Node structure with constructor
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Linked list implementaion of stack
struct Mystack
{
    // init stack vars
    Node *head;
    int sz;

    // initialize stack
    Mystack()
    {
        head = NULL;
        sz = 0;
    }

    // push value in stack
    void push(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        sz++;
    }

    // pop value from stack
    int pop()
    {
        if (head == NULL)
            return INT_MIN;

        // store data to return
        int res = head->data;

        // delete head node
        Node *temp = head;
        head = head->next;
        delete temp;
        sz--;

        // return popped data
        return res;
    }

    // top data
    int peek()
    {
        // if stack is empty
        if (head == NULL)
            return INT_MIN;

        // return top value
        return head->data;
    }

    // size of stack
    int size()
    {
        return sz;
    }

    // check if stack empty
    bool isEmpty()
    {
        return head == NULL;
    }
};

// Driver code
int main()
{
    // Init stack
    Mystack s1;

    // push values
    s1.push(10);
    s1.push(30);
    s1.push(30);

    // Print stack items
    for (int i = 0; i < 3; i++)
    {
        cout << s1.peek() << " ";
        s1.pop();
    }
}