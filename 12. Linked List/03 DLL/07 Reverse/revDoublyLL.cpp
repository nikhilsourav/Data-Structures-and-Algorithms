/*
    Reverse a doubly linked list
    eg: [1<=>2<=>3] => [3<=>2<=>1]
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Reverse list
Node *reverseList(Node *head)
{
    // list has 0 or 1 item
    if (head == NULL || head->next == NULL)
        return head;

    // init prev to point at previous and ptr to traverse
    Node *previous = NULL, *ptr = head;

    // traverse and swap
    while (ptr != NULL)
    {
        previous = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = previous;
        ptr = ptr->prev;
    }

    // return new head pointer
    return previous->prev;
}

// Print list
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
    // Create a new linked list in heap
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Link them
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Print
    printList(head);

    // Reverse
    head = reverseList(head);

    // Print
    printList(head);
}
