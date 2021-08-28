#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// reverse list
Node *reverseList(Node *head)
{
    // list has 0 or 1 item
    if (head == NULL || head->next == NULL)
        return head;

    // init prev to point at previous and ptr to traverse
    Node *prev = NULL, *ptr = head;

    // traverse and swap
    while (ptr != NULL)
    {
        prev = ptr->prev;
        ptr->prev = ptr->next;
        ptr->next = prev;
        ptr = ptr->prev;
    }

    // return new head pointer
    return prev->prev;
}

// print list
void printList(Node *ptr)
{
    // print logic
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
    // create a new linked list in heap
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // link them
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // print
    printList(head);

    // reverse
    head = reverseList(head);

    // print
    printList(head);
}
