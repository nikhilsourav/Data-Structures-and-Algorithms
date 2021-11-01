/*
    Incomplete
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
    // allocate memory to new node
    Node *newNode = new Node(val);

    // if list is empty and pos == 1, simply return new node
    if (pos == 1 && head == NULL || head == NULL)
        return newNode;

    // if list is not empty and pos == 1
    if (pos == 1)
    {
        newNode->next = head;
        head->prev = newNode;
        return newNode;
    }

    // general case: insertion at given pos, init ptr to traverse
    Node *ptr = head;

    // traverse and update ptr
    for (int i = 1; i <= pos - 2 && ptr != NULL; i++)
        ptr = ptr->next;

    // while traversing if ptr becomes NULL => pos > list.size()
    if (ptr == NULL)
        return head;

    // ptr->next == NULL after traversing => insert at back
    if (ptr->next == NULL)
    {
        ptr->next = newNode;
        newNode->prev = ptr;
        return head;
    }

    // adjust links
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
    head = insertPos(head, 70, 4);

    // print
    printList(head);
}

// https://bit.ly/3qHNdnQ