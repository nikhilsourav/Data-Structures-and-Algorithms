/*
    Insert an item at the beginning of a linked list
    eg: [1->2->3], 7 => [7->1->2->3]
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

// Insert beginning
Node *insertBeginning(Node *head, int val)
{
    // create new head pointer
    Node *newHead;

    // create new Node and initialize with val (using constructor)
    newHead = new Node(val);

    // point newHead to old head
    newHead->next = head;

    // return new Head
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
    // Creat new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Print Given list
    printList(head);

    // Insert in beginning (update current head, newHead can also be used)
    head = insertBeginning(head, 5);

    // Print after insertion
    printList(head);

    // ============ Empty linked list ============= //
    // Create empty linked list
    Node *head2 = NULL;

    // Insert items (store pointer returned in same head, diff can be used)
    head2 = insertBeginning(head2, 300);
    head2 = insertBeginning(head2, 200);
    head2 = insertBeginning(head2, 100);

    // Print
    printList(head2);
}
