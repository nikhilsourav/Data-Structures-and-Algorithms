/*
    Implementation of doubly linked list

    Advantages of doubly linked list:

        => can be traversed in both directions
        => Delete in O(1) time
        => Insert / Delete before a given node
        => Insert / Delete from both ends in O(1) time by maintaining tail
    
    Disadvantages of doubly linked list:
    
        => Extra space for prev
        => Code becomes complex
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

    // Output
    cout << head->prev << " " << head->data << " " << head->next << "\n";
    cout << second->prev << " " << second->data << " " << second->next << "\n";
    cout << third->prev << " " << third->data << " " << third->next << "\n";

    // These values are same
    cout << "\nThese addresses are same:\n";
    cout << &(head->prev) << " " << (second->prev) << "\n";
    cout << head->next << " " << &(second->prev) << "\n";
    cout << second->next << " " << &(third->prev) << "\n";
    cout << head->prev << " " << third->next << "\n";
}