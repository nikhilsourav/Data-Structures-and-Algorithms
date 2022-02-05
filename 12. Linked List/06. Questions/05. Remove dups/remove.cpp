/*
    Given a sorted signly linked list, remove all duplicates
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

// ================= Remove duplicates using two pointer =============== //
// Remove head
Node *deleteHead(Node *head)
{
    if (head == NULL)
        return NULL;
    Node *newHead = head->next;
    delete head;
    return newHead;
}

// Remove dups
Node *removeDups(Node *head)
{
    // remove duplicates using two pointer (similar to array)
    Node *i = head, *j = head;

    // logic:
    while (j != NULL)
    {
        // check
        if (i->data != j->data)
        {
            i = i->next;
            i->data = j->data;
        }

        // increment j
        j = j->next;
    }

    // assing i->next to temp (for deletion of remaining nodes)
    Node *temp = i->next;

    // mark end of list
    i->next = NULL;

    // delete remaining nodes from heap
    while (temp != NULL)
        temp = deleteHead(temp);

    // return given head
    return head;
}

// ================= Remove duplicates =============== //
Node *removeDup(Node *head)
{
    // traverse pointer ptr
    Node *ptr = head;

    // logic
    while (ptr != NULL && ptr->next != NULL)
    {
        // if adjacent element equal
        if (ptr->data == ptr->next->data)
        {
            Node *temp = ptr->next;
            ptr->next = ptr->next->next;
            delete temp;
        }
        // update ptr for next iteration
        else
            ptr = ptr->next;
    }

    // return
    return head;
}

// Driver code
int main()
{
    // Create linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(20);
    head->next->next->next = new Node(40);

    // Print
    printList(head);

    // Remove duplicates
    head = removeDup(head);

    // Print
    printList(head);
}
