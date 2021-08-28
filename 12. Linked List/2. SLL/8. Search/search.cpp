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

// iterative search
int itrSearch(Node *head, int val)
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

// recursive search
int recSearch(Node *head, int x)
{
    // base case
    if (head == NULL)
        return -1;

    // corner case
    if (head->data == x)
        return 1;
    else
    {
        int res = recSearch(head->next, x);
        if (res == -1)
            return -1;
        else
            return res + 1;
    }
}

// print list
void printList(Node *ptr)
{
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
    // ============ Filled linked list ============= //
    // creat new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // print given list
    printList(head);

    // search
    cout << itrSearch(head, 20) << "\n";
    cout << recSearch(head, 20);
}
