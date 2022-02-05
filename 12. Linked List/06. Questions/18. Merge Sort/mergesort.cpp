/*
    Sort a singly linked list

    eg: 2 -> 3 -> 1 -> 4 -> NULL

    output: 1 -> 2 -> 3 -> 4 -> NULL
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

// Middle element in a linked list
Node *middleElement(Node *head)
{
    // init ptrs
    Node *prevv = NULL, *slow = head, *fast = head;

    // middle element logic
    while (fast != NULL and fast->next != NULL)
    {
        prevv = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    // make first list separate
    prevv->next = NULL;

    // result middle element as new head
    return slow;
}

// Merge two sorted lists
Node *merge(Node *l1, Node *l2)
{
    // corner case
    if (l1 == NULL)
        return l1;
    if (l2 == NULL)
        return l2;

    // for first element
    Node *head = NULL, *tail = NULL;

    if (l1->data <= l2->data)
    {
        head = tail = l1;
        l1 = l1->next;
    }
    else
    {
        head = tail = l2;
        l2 = l2->next;
    }

    // merge logic:
    while (l1 != NULL and l2 != NULL)
    {
        if (l1->data <= l2->data)
        {
            tail->next = l1;
            tail = l1;
            l1 = l1->next;
        }
        else
        {
            tail->next = l2;
            tail = l2;
            l2 = l2->next;
        }
    }

    // connect tail
    if (l1 == NULL)
        tail->next = l2;
    else
        tail->next = l1;

    // return
    return head;
}

// Merge sort in linked list
Node *mergeSort(Node *head)
{
    if (head == NULL or head->next == NULL)
        return head;

    Node *mid = middleElement(head);
    Node *left = mergeSort(head);
    Node *right = mergeSort(mid);
    return merge(left, right);
}

// Driver code
int main()
{
    // Create a linked list
    Node *head = new Node(4);
    head->next = new Node(2);
    head->next->next = new Node(1);
    head->next->next->next = new Node(3);

    // Print
    printlist(head);

    // fn call
    head = mergeSort(head);

    // Print
    printlist(head);
}
