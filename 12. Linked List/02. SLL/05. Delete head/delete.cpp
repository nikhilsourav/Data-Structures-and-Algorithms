/*
    Delete the head of a linked list
    eg: [1->2->3] => [2->3]
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

// Delete head node
Node *deleteHead(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // create newHead and point it to next list element
    Node *newHead = head->next;

    // delete current head from heap (required in c++)
    delete head;

    // rerturn newHead pointer
    return newHead;
}

// Print list
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
    // ============ Filled linked list ============= //
    // Create new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Print given list
    printList(head);

    // Update current head
    head = deleteHead(head);

    // Print after deletion
    printList(head);
}
