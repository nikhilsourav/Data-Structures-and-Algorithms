/*
    Given a sorted signly linked list, 
    getIntersection even and odd nodevenStart retaining order 
    eg:
        i/p: 17->15->8->12->10->5->4
        o/p: 8->12->10->4->17->15->5

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

// size of list
int getCount(Node *head)
{
    // curr to traverse
    Node *curr = head;

    // init count
    int count = 0;

    // count logic:
    while (curr != NULL)
    {
        count++;
        curr = curr->next;
    }

    // answer
    return count;
}

// get intersection logic
int _getIntersection(int diff, Node *head1, Node *head2)
{
    // init two pointers to traverse
    Node *current1 = head1;
    Node *current2 = head2;

    // move list 'diff' unit forward
    for (int i = 0; i < diff; i++)
    {
        if (current1 == NULL)
            return -1;
        current1 = current1->next;
    }

    // after both list start at equal length, find data
    while (current1 != NULL && current2 != NULL)
    {
        if (current1 == current2)
            return current1->data;

        current1 = current1->next;
        current2 = current2->next;
    }

    // if not found
    return -1;
}

// get intersection given function
int getIntersection(Node *head1, Node *head2)
{
    // size of each list
    int count1 = getCount(head1);
    int count2 = getCount(head2);

    // init difference variable
    int diff;

    // logic
    if (count1 > count2)
        diff = count1 - count2;
    else
        diff = count2 - count1;

    // answer
    return _getIntersection(diff, head2, head1);
}

// Driver code
int main()
{
    /* 
		Creation of two linked lists 
	
		1st 3->6->9->15->30 
		2nd 10->15->30 
	
		15 is the intersection point 
	*/

    Node *newNode;

    Node *head1 = new Node(10);

    Node *head2 = new Node(3);

    newNode = new Node(6);
    head2->next = newNode;

    newNode = new Node(9);
    head2->next->next = newNode;

    newNode = new Node(15);
    head1->next = newNode;
    head2->next->next->next = newNode;

    newNode = new Node(30);
    head1->next->next = newNode;

    head1->next->next->next = NULL;

    // fn call
    cout << getIntersection(head1, head2);
}
