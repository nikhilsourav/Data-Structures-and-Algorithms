/*
    Given a singly linked list, reverse it.
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Reverse given linked list
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
    return before;
}

// Print
void printList(Node *ptr)
{
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
    // Create linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Print
    printList(head);

    // Reverse list
    head = reverseList(head);

    // Print
    printList(head);
}
