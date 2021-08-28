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

// insert beginning
Node *insertBeginning(Node *head, int val)
{
    // create new head pointer
    Node *newHead;

    // create new Node and initialize with val (using constructor)
    newHead = new Node(val);

    // point newHead to old head
    newHead->next = head;

    // return new Head
    return newHead;
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

    // print Given list
    printList(head);

    // insert in beginning (update current head, newHead can also be used)
    head = insertBeginning(head, 5);

    // print after insertion
    printList(head);

    // ============ Empty linked list ============= //
    // create empty linked list
    Node *head2 = NULL;

    // insert items (store pointer returned in same head, diff can be used)
    head2 = insertBeginning(head2, 300);
    head2 = insertBeginning(head2, 200);
    head2 = insertBeginning(head2, 100);

    // print
    printList(head2);
}
