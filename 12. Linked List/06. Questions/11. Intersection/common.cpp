/*
    https://bit.ly/3LeBvLh

    Given two signly linked list, Find intersection point
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

int intersectPoint(Node *head1, Node *head2)
{
    // init vars
    Node *curr1 = head1, *curr2 = head2;
    int size1 = 0, size2 = 0;

    // size of first list
    while (curr1 != NULL)
    {
        size1++;
        curr1 = curr1->next;
    }

    // size of second list
    while (curr2 != NULL)
    {
        size2++;
        curr2 = curr2->next;
    }

    // difference between size
    int diff = size1 >= size2 ? size1 - size2 : size2 - size1;

    // adjust size
    if (size1 >= size2)
        for (int i = 0; i < diff; i++)
            head1 = head1->next;
    else
        for (int i = 0; i < diff; i++)
            head2 = head2->next;

    // find required node
    while (head1 != head2)
    {
        head1 = head1->next;
        head2 = head2->next;
    }

    // result
    return head1->data;
}

// Driver code
int main()
{
    /*
        Create two linked lists

        First list: 10->15->30
        Second list: 3->6->9->15->30

        15 is the intersection point
    */

    // Common node
    Node *common = new Node(15);

    // First list
    Node *head1 = new Node(10);
    head1->next = common;
    head1->next->next = new Node(30);

    // Second list
    Node *head2 = new Node(3);
    head2->next = new Node(6);
    head2->next->next = new Node(9);
    head2->next->next->next = common;
    head2->next->next->next->next = new Node(30);

    // fn call
    cout << intersectPoint(head1, head2);
}
