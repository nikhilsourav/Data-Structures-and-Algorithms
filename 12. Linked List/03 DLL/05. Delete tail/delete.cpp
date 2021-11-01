/*
    Delete the tail of a doubly linked list
    eg: [1<=>2<=>3] => [1<=>2]
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

// Delete tail
Node *deleteTail(Node *head)
{
    // if list is empgy
    if (head == NULL)
        return NULL;

    // if list has only 1 element
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // general case traverse to second last
    Node *curr = head;
    while (curr->next->next != NULL)
        curr = curr->next;

    // delete last node
    delete curr->next;

    // make second last node's next NULL
    curr->next = NULL;

    // return given head
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

    // Delete tail
    head = deleteTail(head);

    // Print
    printList(head);
}
