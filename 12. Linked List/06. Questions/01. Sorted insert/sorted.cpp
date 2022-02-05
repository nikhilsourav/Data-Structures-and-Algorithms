/*
    Given a sorted singly linked list, insert an item 
    retaining the order of the linked list
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

// Insert item in singly linked list retaining order
Node *insert(Node *head, int val)
{
    // create a node
    Node *newNode = new Node(val);

    // if list is empty
    if (head == NULL)
        return newNode;

    // if val fits as first item
    if (val < head->data)
    {
        newNode->next = head;
        return newNode;
    }

    // traverse to correct position
    Node *ptr = head;
    while (ptr->next != NULL && ptr->next->data < val)
        ptr = ptr->next;

    // insert newNode
    newNode->next = ptr->next;
    ptr->next = newNode;

    // return
    return head;
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
    // Create linked list with data in ascending order
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Print
    printList(head);

    // Insert
    head = insert(head, 25);

    // Print
    printList(head);
}
