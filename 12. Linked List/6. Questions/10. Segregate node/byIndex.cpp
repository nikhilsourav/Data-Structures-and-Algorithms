#include <bits/stdc++.h>
using namespace std;

// node Struct
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr){};
    ListNode(int x) : val(x), next(nullptr){};
    ListNode(int x, ListNode *next) : val(x), next(next){};
};

// segregate even and odd
ListNode *oddEvenList(ListNode *head)
{
    // corner case
    if (head == NULL)
        return head;
    else if (head->next == NULL)
        return head;

    // init pointers
    ListNode *oddStart = NULL, *oddEnd = NULL, *evenStart = NULL, *evenEnd = NULL;

    // logic:
    int count = 0;
    while (head != NULL)
    {
        count++;

        // odd index
        if (count % 2 != 0)
        {
            // if this is first iteration
            if (oddStart == NULL)
            {
                oddStart = head;
                oddEnd = oddStart;
            }
            // subsequent iterations
            else
            {
                oddEnd->next = head;
                oddEnd = oddEnd->next;
            }
        }
        // even index
        else
        {
            // if this is first iteration
            if (evenStart == NULL)
            {
                evenStart = head;
                evenEnd = evenStart;
            }
            // subsequent iterations
            else
            {
                evenEnd->next = head;
                evenEnd = evenEnd->next;
            }
        }

        // update for next iteration
        head = head->next;
    }

    // attach both list and make last node's next = NULL
    oddEnd->next = evenStart;
    evenEnd->next = NULL;

    // return ptr
    return oddStart;
}

// prinlist
void printList(ListNode *head)
{
    while (head != NULL)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << "\n";
}

// Driver code
int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    printList(head);
    head = oddEvenList(head);
    printList(head);
}