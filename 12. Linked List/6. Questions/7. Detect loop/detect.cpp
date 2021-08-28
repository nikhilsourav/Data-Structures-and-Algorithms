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

// check whether linked list has loops
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

// Driver code
int main()
{
    // create linked list with loop
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head;

    // detect loop
    cout << boolalpha << hasLoop(head);
}
