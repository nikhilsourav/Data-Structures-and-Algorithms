/*
    Given a sorted signly linked list, check whether it has loops
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

// Floyd cycle detection
bool hasLoop(Node *head)
{
    // init slow and fast
    Node *slow = head, *fast = head;

    // loop detection logic
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }

    // if no loop
    return false;
}

// Driver code
int main()
{
    // Create linked list with loop
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    // Detect loop
    cout << boolalpha << hasLoop(head);
}
