/*
    // https://bit.ly/3qHNdnQ

    Given a doubly linked list insert a node at given position
    The item's index should be the given index (pos) after insertion

    list [1<=>2<=>3]
    item: 70, pos = 1 (0-based index)

    output: [1<=>70<=>2<=>3]
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int x)
    {
        data = x;
        next = NULL;
        prev = NULL;
    }
};

// insert
Node *insertPos(Node *head, int val, int pos)
{
    Node *newNode = new Node(val);

    /*
        Case 1: If pos == 0
            if list == empty and pos == 0
            simply return newNode

            if list != empty and pos == 0
            connect new node to head
    */
    if (pos == 0 and head == NULL || head == NULL)
        return newNode;
    if (pos == 0 and head != NULL)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    /*
        Case 2: If pos > 0
            Start from i = 0 and reach one node before pos node
            Note that the loop will run from [0 to pos - 1)

            if(ptr == null) return;
            if(ptr->next == null) logic: insert at back return;
            else Rearrange links
    */
    // take ptr to one node before pos
    Node *ptr = head;
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
        ptr = ptr->next;

    // check
    if (ptr == NULL)
        return head;

    // extra case: insert at back
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        return head;
    }

    // rearrange links
    newNode->next = ptr->next;
    ptr->next->prev = newNode;
    ptr->next = newNode;
    newNode->prev = ptr;

    // return given head
    return head;
}

// print list
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
    // create a new linked list in heap
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // link them
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // print
    printList(head);

    // insert 70 at pos 2
    head = insertPos(head, 70, 2);

    // print
    printList(head);
}