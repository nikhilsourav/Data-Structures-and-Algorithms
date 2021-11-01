/*
    Insert an item at the end of a linked list
    eg: [1->2->3], 7 => [1->2->3->7]
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

// Insert end
Node *insertEnd(Node *head, int val)
{
    // allocate memory for new node
    Node *newNode = new Node(val);

    // if head is null return newly created node itself
    if (head == NULL)
        return newNode;

    // if head is not null traverse to end and then insert newNode node
    // temp pointer ptr will be used to traverse and head will be returned
    Node *ptr = head;

    // check if current node's next is NULL. Had we written only ptr != NULL
    // after loop execution ptr would be NULL so we coudn't attach newNode to it
    while (ptr->next != NULL)
        ptr = ptr->next;

    // This is the last node so attach newNode and return given head pointer
    ptr->next = newNode;

    // retrun given head itself
    return head;
}

// Print list
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
    // Create new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    // Print given list
    printList(head);

    // Insert 40 at end
    head = insertEnd(head, 40);

    // Print after insertion
    printList(head);

    // ============ Empty linked list ============= //
    // Create empty linked list
    Node *head2 = NULL;

    // Insert multiple values
    head2 = insertEnd(head2, 100);
    head2 = insertEnd(head2, 200);
    head2 = insertEnd(head2, 300);

    // Print after insertion
    printList(head2);
}
