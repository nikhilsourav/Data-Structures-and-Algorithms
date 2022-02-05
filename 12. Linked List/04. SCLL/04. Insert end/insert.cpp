/*
    Insert at the end of a singly circular linked list
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

// Insert in the end O(1)
Node *insertEnd(Node *head, int val)
{
    // create node
    Node *newNode = new Node(val);

    // if list is empty
    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    // insert node at 2nd pos and swap data of 1st and 2nd
    // insert newHead
    newNode->next = head->next;
    head->next = newNode;

    // swap
    int temp = newNode->data;
    newNode->data = head->data;
    head->data = temp;

    // return
    return newNode;
}

// Print list
void printList(Node *head)
{
    // if list is empty
    if (head == NULL)
        return;

    // print logic
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);

    // newline
    cout << "\n";
}

// Driver code
int main()
{
    // Create a singly circular linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // last node point to head

    // Print
    printList(head);

    // Insert
    head = insertEnd(head, 5);

    // Print
    printList(head);
}
