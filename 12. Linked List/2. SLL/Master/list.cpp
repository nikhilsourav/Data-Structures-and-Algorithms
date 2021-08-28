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

// utility fn
void msg(string str)
{
    cout << str << "\n";
}

// print list
void printList(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n\n";
}

// insert a node in the beginning
Node *insert_front(Node *head, int val)
{
    Node *newHead = new Node(val);
    newHead->next = head;
    return newHead;
}

// insert node at the back
Node *insert_back(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
        return newNode;
    Node *current = head;
    while (current->next != NULL)
        current = current->next;
    current->next = newNode;
    return head;
}

// delete head
Node *pop_front(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *ptr = head->next;
    delete head;
    return ptr;
}

// delete tail
Node *pop_back(Node *head)
{
    if (head == NULL)
        return NULL;
    if (head->next == NULL)
    {
        delete head;
        return NULL;
    }
    Node *ptr = head;
    while (ptr->next->next != NULL)
        ptr = ptr->next;
    delete ptr->next;
    ptr->next = NULL;
    return head;
}

// insert at position
Node *insert_at(Node *head, int pos, int val)
{
    Node *newNode = new Node(val);
    if (pos == 1)
    {
        newNode->next = head;
        return newNode;
    }
    Node *ptr = head;
    for (int i = 1; i <= pos - 2 && ptr != NULL; i++)
        ptr = ptr->next;
    if (ptr == NULL)
        return head;
    newNode->next = ptr->next;
    ptr->next = newNode;
    return head;
}

// search
int search(Node *head, int val)
{
    int pos = 1;
    while (head != NULL)
    {
        if (head->data == val)
            return pos;
        else
        {
            pos++;
            head = head->next;
        }
    }
    return -1;
}

// Driver code
int main()
{
    // create list with 3 values
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    msg("Given List");
    printList(head); // 10 20 30

    // insert front
    head = insert_front(head, 5);
    msg("Insert front (5)");
    printList(head); // 5 10 20 30

    // insert back
    head = insert_back(head, 35);
    msg("Insert back (35)");
    printList(head); // 5 10 20 30 35

    // delete front
    head = pop_front(head);
    msg("Delete front");
    printList(head); // 10 20 30 35

    // delete back
    head = pop_back(head);
    msg("Delete back");
    printList(head); // 10 20 30

    // insert at position
    head = insert_at(head, 2, 70);
    msg("Insert 70 at pos 2");
    printList(head); // 10 70 20 30

    // search
    int idx = search(head, 70);
    msg("Search value 70");
    cout << 70 << " found at pos " << idx;
}