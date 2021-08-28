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

// delete tail
Node *deleteTail(Node *head)
{
    // if list is empty
    if (head == NULL)
        return NULL;

    // if list has 1 element
    if (head->next == head)
    {
        delete head;
        return NULL;
    }

    // traverse to second last
    Node *ptr = head;
    while (ptr->next->next != head)
        ptr = ptr->next;

    // store pointer to last element
    Node *temp = ptr->next;

    // adjust second last to head
    ptr->next = head;

    // delete last
    delete temp;
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
    head = deleteTail(head);

    // print
    printList(head);
}
