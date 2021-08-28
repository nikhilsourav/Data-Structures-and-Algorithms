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

// delete head
Node *deleteHead(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // if list has 1 element
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }

    // copy head to temp (temp points to 1st node)
    Node *temp = head;

    // move head to next node (head points to 2nd node)
    head = head->next;

    // head->prev = NULL to mark this as first node
    head->prev = NULL;

    // delete first node (represented by temp)
    delete temp;

    // return new head
    return head;
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

    // delete head
    head = deleteHead(head);

    // print
    printList(head);
}
