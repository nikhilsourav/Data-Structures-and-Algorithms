/*
    Insert a node at the beginning of the doubly linked list
    eg: [1<=>2<=>3], 4 => [4<=>1<=>2<=>3]
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

// Insert Node in beginning
Node *insertBegin(Node *head, int val)
{
    // create newHead
    Node *newHead = new Node(val);

    // link newHead->next to head
    newHead->next = head;

    // if list is not empty head->prev = newHead
    if (head != NULL)
        head->prev = newHead;

    // return newHead pointer
    return newHead;
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

    // Insert
    head = insertBegin(head, 40);

    // Print
    printList(head);
}