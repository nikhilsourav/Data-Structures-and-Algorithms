/*
    Given a singly linked list, left-shift the
    linked list by k nodes, where k is a given
    positive integer smaller than or equal to
    length of the linked list.

    arr[] = {2, 4, 7, 8, 9};
    k = 3;
    
    output: 8, 9, 2, 4, 7
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

// Print
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// Rotate list k times
Node *rotateList(Node *head, int k)
{
    // take current pointer to tail
    Node *curr = head;

    while (curr->next != NULL)
        curr = curr->next;

    // swap
    for (int i = 0; i < k; i++)
    {
        curr->next = head;
        head = head->next;
        curr = curr->next;
        curr->next = NULL;
    }

    // ans
    return head;
}

// Driver code
int main()
{
    // create a linked list
    Node *head = new Node(2);
    head->next = new Node(4);
    head->next->next = new Node(7);
    head->next->next->next = new Node(8);
    head->next->next->next->next = new Node(9);
    int k = 3;

    // print
    printlist(head);

    // fn call
    head = rotateList(head, k);

    // print
    printlist(head);
}
