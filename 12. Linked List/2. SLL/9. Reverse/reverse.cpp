// https://www.youtube.com/watch?v=XgABnoJLtG4

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// reverse list
Node *reverseList(Node *head)
{
    // init before and after pointer
    Node *before = NULL, *after = NULL;

    // logic
    while (head != NULL)
    {
        after = head->next;
        head->next = before;
        before = head;
        head = after;
    }

    // answer
    head = before;
    return head;
}

// print list
void printList(Node *ptr)
{
    // print logic
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Driver code
int main()
{
    // creat new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // print given list
    printList(head);

    // reverse
    head = reverseList(head);

    // print
    printList(head);
}
