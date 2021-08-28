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

// delete head
Node *deleteHead(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // if list has one element
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    // copy 2nd node's data to first
    head->data = head->next->data;

    // link 1st node to third node
    Node *ptr = head->next;
    head->next = ptr->next;

    // delete 2nd node
    delete ptr;
    return head;
}

// print list
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
    // create a singly circular linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // last node point to head

    // print
    printList(head);

    // delete
    head = deleteHead(head);

    // print
    printList(head);
}
