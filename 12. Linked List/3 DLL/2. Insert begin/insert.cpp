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

// insert Node in beginning
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

    // insert
    head = insertBegin(head, 40);

    // print
    printList(head);
}