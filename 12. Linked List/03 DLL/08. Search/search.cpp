/*
    Search for an item in a doubly linked list
    eg: [1<=>2<=>3], 2 => position = 2
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    Node *prev;
    int data;
    Node *next;

    // constructor
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

// Search in list
int search(Node *head, int val)
{
    // init position
    int pos = 1;

    // init ptr to traverse
    Node *ptr = head;

    // traverse and check values
    while (ptr != NULL)
    {
        if (ptr->data == val)
            return pos;
        else
        {
            pos++;
            ptr = ptr->next;
        }
    }

    // if not found
    return -1;
}

// Print list
void printList(Node *ptr)
{
    // print logic
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
    // Create a new linked list in heap
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Link them
    head->next = second;
    second->prev = head;
    second->next = third;
    third->prev = second;

    // Search list for 30
    cout << search(head, 30);
}
