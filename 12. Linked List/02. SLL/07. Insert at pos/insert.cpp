/*
    Insert an item at a given position in the linked list
    The item's index should be the given index (pos) after insertion

    list = [1->2->3->4],
    item = 5, pos = 1 (0-based indexing)

    output: [1->5->2->3->4]
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

/*
    Case 1: If pos == 0
        Create newNode with val, newNode->next = head

    Case 2: If pos > 1
        Start from i = 0 and reach one node before pos node
        Note that the loop will run from [0 to pos - 1)
        
        for(i = 0; i < pos - 1 and head != NULL; i++)
            prt = prt->next;

        Rearrange links
*/

// Insert at position
Node *insertPos(Node *head, int pos, int val)
{
    // allocate new node in heap
    Node *newNode = new Node(val);

    // if position is 0
    if (pos == 0)
    {
        newNode->next = head;
        return newNode;
    }

    // for general case init ptr to traverse list
    Node *ptr = head;

    // reach pos by updating ptr
    for (int i = 0; i < pos - 1 && ptr != NULL; i++)
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
    head->next->next->next = new Node(40);

    // Print given list
    printList(head);

    // Insert at 2nd position (index = 1)
    head = insertPos(head, 2, 50);

    // Print after insertion
    printList(head);
}
