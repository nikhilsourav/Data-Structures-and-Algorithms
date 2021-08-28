/*
    Given a sorted signly linked list, 
    segregate even and odd nodevenStart retaining order 
    eg:
        i/p: 17->15->8->12->10->5->4
        o/p: 8->12->10->4->17->15->5

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

// segregate
Node *segregate(Node *head)
{
    // init vars
    Node *evenStart = NULL, *evenEnd = NULL, *oddStart = NULL, *oddEnd = NULL;

    // logic:
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        // check current data
        int x = curr->data;

        // even
        if (x % 2 == 0)
        {
            // for first iteration
            if (evenStart == NULL)
            {
                evenStart = curr;
                evenEnd = evenStart;
            }
            // for subsequent iteration
            else
            {
                evenEnd->next = curr;
                evenEnd = evenEnd->next;
            }
        }
        // odd
        else
        {
            // for first iteration
            if (oddStart == NULL)
            {
                oddStart = curr;
                oddEnd = oddStart;
            }
            // for subsequent iteration
            else
            {
                oddEnd->next = curr;
                oddEnd = oddEnd->next;
            }
        }
    }

    // if given list has only odd or only even
    if (oddStart == NULL || evenStart == NULL)
        return head;

    // connect even and odd node
    evenEnd->next = oddStart;
    // set last node
    oddEnd->next = NULL;

    // return new head
    return evenStart;
}

// Driver code
int main()
{
    // create linked list
    Node *head = new Node(17);
    head->next = new Node(15);
    head->next->next = new Node(8);
    head->next->next->next = new Node(12);
    head->next->next->next->next = new Node(10);
    head->next->next->next->next->next = new Node(5);
    head->next->next->next->next->next->next = new Node(4);

    // print
    printList(head);

    // segregate elements
    head = segregate(head);

    // print
    printList(head);
}
