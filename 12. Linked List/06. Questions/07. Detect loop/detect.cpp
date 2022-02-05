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

// Method 1: Hashing
bool hasLoop(Node *head)
{
    // store elements while traversing
    unordered_set<int> store;

    // check loop
    while (head != NULL)
    {
        if (store.find(head->data) != store.end())
            store.insert(head->data);
        else
            return true;
        head = head->next;
    }

    // if no loop
    return false;
}

// Method 2: Floyd's algorithm
bool checkLoop(Node *head)
{
    Node *slow = head, *fast = head;
    while (fast != NULL and fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return true;
    }
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
    cout << boolalpha << checkLoop(head);
}
