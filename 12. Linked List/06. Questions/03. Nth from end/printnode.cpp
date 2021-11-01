/*
    Given a singly linked list, find value at nth node from end
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

// insert
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

// print
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
    // create linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // print
    printList(head);

    // value of nth node from end
    cout << nthFromEnd(head, 3);
}