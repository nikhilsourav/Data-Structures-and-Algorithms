/*
    Insert at the beginning of a singly circular linked list
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

// Insert in the beginning O(1)
Node *insertBegin(Node *head, int val)
{
    // create new node
    Node *newHead = new Node(val);

    // if list is empty
    if (head == NULL)
    {
        newHead->next = newHead;
        return newHead;
    }

    // insert after 1st node and swap data of 1st and 2nd
    // insert newHead
    newHead->next = head->next;
    head->next = newHead;

    // swap data
    int temp = head->data;
    head->data = newHead->data;
    newHead->data = temp;

    // return
    return head;
}

// Print list
void printList(Node *head)
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
    // Create a singly circular linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // last node point to head

    // Print
    printList(head);

    // Insert
    head = insertBegin(head, 5);

    // Print
    printList(head);
}
