/*
    Delete the head of a doubly linked list
    eg: [1<=>2<=>3] => [2<=>3]
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

// Delete head
Node *deleteHead(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // if list has 1 element
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // copy head to temp (temp points to 1st node)
    Node *temp = head;

    // move head to next node (head points to 2nd node)
    head = head->next;

    // head->prev = NULL to mark this as first node
    head->prev = NULL;

    // delete first node (represented by temp)
    delete temp;

    // return new head
    return head;
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

    // Delete head
    head = deleteHead(head);

    // Print
    printList(head);
}
