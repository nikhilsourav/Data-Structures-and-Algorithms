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

// Driver code
int main()
{
    // create a singly circular linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head; // last node point to head
}

/*
    Advantages of circular linked list:

        => whole list can be traversed from any node
        => implementation of algorithm like round robin
        => Insert at begin / end by only maintaining one tail pointer
    
    Disadvantages of circular linked list:
    
        => Implementation of operations becomes complex :(
*/