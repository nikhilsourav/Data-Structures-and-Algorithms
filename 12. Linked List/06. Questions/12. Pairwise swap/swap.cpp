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
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

// pairwise swap list without data swapping
Node *pairwiseSwap(Node *head)
{
    // corner case
    if (head == NULL || head->next == NULL)
        return head;

    // set head
    Node *curr = head->next->next;
    Node *prev = head;
    head = head->next;
    head->next = prev;

    // logic
    while (curr != NULL && curr->next != NULL)
    {
        prev->next = curr->next;
        prev = curr;
        Node *next = curr->next->next;
        curr->next->next = curr;
        curr = next;
    }

    // answer
    prev->next = curr;
    return head;
}

// Driver code
int main()
{
    // create a linked list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // print
    printlist(head);

    // fn call
    head = pairwiseSwap(head);

    // print
    printlist(head);
}
