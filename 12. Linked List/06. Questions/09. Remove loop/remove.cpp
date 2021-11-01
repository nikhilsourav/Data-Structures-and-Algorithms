/*
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

// print
void printList(Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// detect and remove loop
Node *removeLoop(Node *head)
{
    // init fast and slow pointer
    Node *slow = head, *fast = head;

    // detect loop using floyd cycle detection
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            break;
    }

    // if there is no loop
    if (slow != fast)
        return head;

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
    return head;
}

// Driver code
int main()
{
    // create linked list with loop
    Node *head = new Node(15);
    head->next = new Node(10);
    head->next->next = new Node(12);
    head->next->next->next = new Node(20);
    head->next->next->next->next = head->next;

    // detect and remove loop
    head = removeLoop(head);

    // print
    printList(head);
}
