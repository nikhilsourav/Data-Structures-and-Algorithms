/*
    Delete the tail of a linked list
    eg: [1->2->3] => [1->2]
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

// Delete tail node
Node *deleteTail(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // if list has only one node
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // general case make a copy of head to traverse
    Node *ptr = head;

    // stop at one element before the last
    while (ptr->next->next != NULL)
        ptr = ptr->next;

    // delete last node
    delete ptr->next;

    // point second last node to NULL
    ptr->next = NULL;

    // return given head
    return head;
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
    head = deleteTail(head);

    // Print list after tail deletion
    printList(head);
}
