/*
    Traverse and print elements of singly circular linked list
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

// print list
void printList_1(Node *head)
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

// print list
void printList_2(Node *head)
{
    // if list is empty
    if (head == NULL)
        return;

    // print logic
    cout << head->data << " ";
    for (Node *ptr = head->next; ptr != head; ptr = ptr->next)
        cout << ptr->data << " ";

    // newline
    cout << "\n";
}

// Driver code
int main()
{
    // create a singly circular linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // last node point to head

    // print
    printList_2(head);
}
