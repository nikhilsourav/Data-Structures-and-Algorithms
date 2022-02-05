/*
    You are given two non-empty linked lists representing
    two non-negative integers. The digits are stored in reverse
    order, and each of their nodes contains a single digit.
    Add the two numbers and return the sum as a linked list.

    You may assume the two numbers do not contain any leading
    zero, except the number 0 itself.

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]

    Explanation: 342 + 465 = 807.

    https://leetcode.com/problems/add-two-numbers/submissions/
*/

#include <bits/stdc++.h>
using namespace std;

// Node Structure
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Print list
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Add two numbers
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    // sum list to traverse, head to store first location
    ListNode *sum = new ListNode(0);
    ListNode *head = sum;

    // logic:
    int carry = 0;
    while (l1 != NULL || l2 != NULL)
    {
        // if l1 != NULL and l2 l2 != NULL
        int x = l1 == NULL ? 0 : l1->val;
        int y = l2 == NULL ? 0 : l2->val;

        // current sum
        int currSum = carry + x + y;
        // carry
        carry = currSum / 10;

        // store currSum (even if overflow)
        sum->next = new ListNode(currSum % 10);

        // update sum
        sum = sum->next;

        // update list if possible
        if (l1 != NULL)
            l1 = l1->next;
        if (l2 != NULL)
            l2 = l2->next;
    }

    // if leftover carry is present
    if (carry > 0)
        sum->next = new ListNode(carry);

    // pointer to traverse list
    return head->next;
}

// Driver code
int main()
{
    // first list
    ListNode *l1 = new ListNode(2);
    l1->next = new ListNode(3);
    l1->next->next = new ListNode(3);

    // second list
    ListNode *l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    // fn call
    ListNode *sum = addTwoNumbers(l1, l2);

    // output
    printList(sum);
}