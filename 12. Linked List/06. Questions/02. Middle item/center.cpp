/*
    Given a singly linked list, find the middle element
    if list is even return (n/2 + 1)th element (1 based indexing)
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

// Find middle element
int middleElement(Node *head)
{
    // if list is empty
    if (head == NULL)
        return -1;

    // slow (moves 1 node) and fast (moves two node) at a time
    Node *slow = head, *fast = head;

    // traverse
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // return mid element
    return slow->data;
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
    // Create linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // Print
    printList(head);

    // Print middle element
    cout << middleElement(head);
}
