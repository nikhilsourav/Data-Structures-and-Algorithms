/*
    Given the head of a singly linked list and two integers
    left and right where left <= right, reverse the nodes of
    the list from position left to right and return the reversed list.

    list = 1->2->3->4->5
    left = 2, right = 3

    output = 1->4->3->2->5
*/

#include <bits/stdc++.h>
using namespace std;

// ListNode class with constructor
class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int x)
    {
        data = x;
        next = NULL;
    }
};

/*
    First locate the node before the left node (pre)
    and also locate the left node (curr). Then move
    curr -> next to be after pre for right - left times.

*/
ListNode *reverseBetween(ListNode *head, int left, int right)
{
    // init ndoes
    ListNode *sentinal = new ListNode(0), *pre = sentinal, *curr = NULL;
    sentinal->next = head;

    // find node just before left node
    for (int i = 0; i < left - 1; i++)
        pre = pre->next;

    // find left node
    curr = pre->next;

    // move curr->next to after pre for r - l times
    for (int i = 0; i < right - left; i++)
    {
        ListNode *temp = pre->next;
        pre->next = curr->next;
        curr->next = curr->next->next;
        pre->next->next = temp;
    }

    // result
    return sentinal->next;
}

// print list
void printList(ListNode *head)
{
    // logic:
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }

    // newline
    cout << endl;
}

// Driver code
int main()
{
    // create linked list
    ListNode *head = new ListNode(10);
    head->next = new ListNode(20);
    head->next->next = new ListNode(30);
    head->next->next->next = new ListNode(40);
    head->next->next->next->next = new ListNode(50);
    head->next->next->next->next->next = new ListNode(60);

    // print
    printList(head);

    // reverse list
    head = reverseBetween(head, 1, 2);

    // print
    printList(head);
}
