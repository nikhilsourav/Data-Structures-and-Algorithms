/*
    https://bit.ly/330rKzb

    Given a sorted signly linked list,
    find and remove a loop if it exists
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

// Print
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Detect and remove loop
void removeLoop(Node *head)
{
    // init fast and slow pointer
    Node *slow = head, *fast = head;

    // detect loop using floyd cycle detection
    while (slow != NULL and fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // check
    if (slow == head)
    {
        while (fast->next != slow)
            fast = fast->next;
        fast->next = NULL;
    }

    if (slow == fast)
    {
        // reset slow
        slow = head;

        // move both pointer together
        while (slow->next != fast->next)
        {
            slow = slow->next;
            fast = fast->next;
        }

        // reset last pointer to NULL
        fast->next = NULL;
    }
}

// Driver code
int main()
{
    // Create linked list with loop
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;

    // Detect and remove loop
    removeLoop(head);

    // Print
    printList(head);
}
