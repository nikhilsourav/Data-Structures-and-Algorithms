/*
    Linked list implementation using struct
*/

#include <bits/stdc++.h>
using namespace std;

// Node structure
struct Node
{
    // data of node (can be int, char, float or custom datatype)
    int data;

    // pointer to next node (because datatype of each node = Node)
    Node *next;

    // constructor to initialize each Node
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Driver code
int main()
{
    // Create three nodes in heap with data initialized by constructor
    Node *head = new Node(10);
    Node *ptr1 = new Node(20);
    Node *ptr2 = new Node(30);

    // Link next pointer of each node to subsequent node
    head->next = ptr1;
    ptr1->next = ptr2;

    // Output
    cout << head->data << " " << head->next << "\n";
    cout << ptr1->data << " " << ptr1->next << "\n";
    cout << ptr2->data << " " << ptr2->next << "\n";

    // Short implementation
    Node *headPtr = new Node(40);
    headPtr->next = new Node(50);
    headPtr->next->next = new Node(60);

    // Output
    cout << headPtr->data << " " << headPtr->next << "\n";
    cout << headPtr->next->data << " " << headPtr->next->next << "\n";
    cout << headPtr->next->next->data << " " << headPtr->next->next->next << "\n";
}