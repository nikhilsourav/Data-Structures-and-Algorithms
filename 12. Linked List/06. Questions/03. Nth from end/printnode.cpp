/*
    Given a singly linked list, find value at nth node from end

    10->20->30->40->50
    n = 3

    output: 30 
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

// Find nth node from end
int nthFromEnd(Node *head, int x)
{
    // if list is empty
    if (head == NULL)
        return -1;

    // two pointer approach
    Node *first = head;
    for (int i = 0; i < x; i++)
    {
        if (first == NULL)
            return -1;
        first = first->next;
    }
    Node *second = head;
    while (first != NULL)
    {
        second = second->next;
        first = first->next;
    }

    // return
    return second->data;
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
    head->next->next->next->next = new Node(50);

    // Print
    printList(head);

    // Value of nth node from end
    cout << nthFromEnd(head, 3);
}
