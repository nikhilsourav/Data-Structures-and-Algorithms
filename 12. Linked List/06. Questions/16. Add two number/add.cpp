// https://leetcode.com/problems/add-two-numbers/submissions/

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

// print list utility
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