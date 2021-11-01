/*
    Traverse and print elements of circular doubly linked list
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// print list
void printlist(Node *head)
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
    // create a circular doubly linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // link them
    head->next = second;
    second->next = third;
    third->next = head;
    second->prev = head;
    third->prev = second;
    head->prev = third;

    // print list
    printlist(head);
}
