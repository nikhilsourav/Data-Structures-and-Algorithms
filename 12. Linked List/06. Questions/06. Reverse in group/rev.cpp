/*
    Given a sorted signly linked list, reverse it in group of k
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
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Reverse in groups
Node *reverseGroups(Node *head, int k)
{
    // init before and after pointer
    Node *before = NULL, *after = NULL, *current = head;

    // count to keep track  fo number < k
    int i = 0;

    // reverse logic
    while (current != NULL && i < k)
    {
        after = current->next;
        current->next = before;
        before = current;
        current = after;
        i++;
    }

    // recursively call for next k elements
    if (after != NULL)
        head->next = reverseGroups(after, k);

    // return previous head
    return before;
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
    head->next->next->next->next->next = new Node(60);
    head->next->next->next->next->next->next = new Node(70);

    // Print
    printList(head);

    // reverse in groups of k
    head = reverseGroups(head, 3);

    // Print
    printList(head);
}
