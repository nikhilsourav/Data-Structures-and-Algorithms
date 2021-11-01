/*
    Implementation of a circular doubly linked list
*/

#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
struct Node
{
    int data;
    Node *prev;
    Node *next;
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
    // Create a circular doubly linked list
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);

    // Link them
    head->next = second;
    second->next = third;
    third->next = head;
    second->prev = head;
    third->prev = second;
    head->prev = third;
}
/*
    * CDLL provides all functionality of circular and doubly linked list
    
    * Access to last node without maintaining extra tail pointer
*/