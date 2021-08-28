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
Node *insertPos(Node *head, int pos, int val)
{
    // allocate new node in heap
    Node *newNode = new Node(val);

    // if position is 1
    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }

    // for general case init ptr to traverse list
    Node *ptr = head;

    // reach pos by updateing ptr
    for (int i = 1; i <= pos - 2 && ptr != NULL; i++)
        ptr = ptr->next;

    // if pos cross list size => ptr == NULL => do nothing
    if (ptr == NULL)
        return head;

    // link new node to ptr->next
    newNode->next = ptr->next;

    // link ptr to new node
    ptr->next = newNode;

    // return given head
    return head;
}

// print list
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
    // ============ Filled linked list ============= //
    // creat new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // print given list
    printList(head);

    // insert at 2nd position
    head = insertPos(head, 2, 50);

    // print after insertion
    printList(head);
}
