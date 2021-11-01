#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    char data;
    Node *next;
    Node(char x)
    {
        data = x;
        next = NULL;
    }
};

// reverse list fn
Node *reverseList(Node *head)
{
    // if list is empty
    if (head == NULL || head->next == NULL)
        return head;

    // reverse logic
    Node *rest_head = reverseList(head->next);
    Node *rest_tail = head->next;
    rest_tail->next = head;
    head->next = NULL;

    // return new head
    return rest_head;
}

// check palindrome
bool isPalindrome(Node *head)
{
    // if list is empty
    if (head == NULL)
        return true;

    // two pointer
    Node *slow = head, *fast = head;

    // middle element
    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse list
    Node *rev = reverseList(slow->next);
    Node *curr = head;

    // palindrome logic
    while (rev != NULL)
    {
        if (rev->data != curr->data)
            return false;
        rev = rev->next;
        curr = curr->next;
    }

    // answer
    return true;
}

// Driver code
int main()
{
    // create new linked list
    Node *head = new Node('g');
    head->next = new Node('f');
    head->next->next = new Node('g');

    // fn call
    cout << boolalpha << isPalindrome(head);
}
