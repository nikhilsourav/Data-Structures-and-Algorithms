/*
    Given two singly linked list.
    Merge two sorted list retaining order
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

// print
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

// sort fn
Node *sortedMerge(Node *head1, Node *head2)
{
    // if list is empty
    if (head1 == NULL)
        return head2;
    if (head2 == NULL)
        return head1;

    // init new list's head and tail
    Node *head = NULL, *tail = NULL;

    // first iteration
    if (head1->data <= head2->data)
    {
        head = tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = tail = head2;
        head2 = head2->next;
    }

    // merge logic
    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            tail = head1;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            tail = head2;
            head2 = head2->next;
        }
    }

    // link tail
    if (head1 == NULL)
        tail->next = head2;
    else
        tail->next = head1;

    // return new list head
    return head;
}

// Driver code
int main()
{
    // create new linked list
    Node *head1 = new Node(10);
    head1->next = new Node(20);
    head1->next->next = new Node(30);
    Node *head2 = new Node(5);
    head2->next = new Node(35);

    // fn call
    printlist(sortedMerge(head1, head2));
}
