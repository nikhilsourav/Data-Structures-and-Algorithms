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

// insert at end
Node *insertEnd(Node *head, int val)
{
    // allocate memory to new node
    Node *newNode = new Node(val);

    // if list is empty
    if (head == NULL)
        return newNode;

    // pointer ptr is used to traverse and head will be returned
    Node *ptr = head;

    // traverse to the end
    while (ptr->next != NULL)
        ptr = ptr->next;

    // insert new node in the end
    ptr->next = newNode;

    // configure newNode->prev to point to current ptr
    newNode->prev = ptr;

    // return head
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
    head = insertEnd(head, 40);

    // print
    printList(head);
}
