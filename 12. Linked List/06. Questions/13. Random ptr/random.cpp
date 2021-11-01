#include <bits/stdc++.h>
using namespace std;

// Node class with constructor
class Node
{
public:
    int data;
    Node *next, *random;
    Node(int x)
    {
        data = x;
        next = random = NULL;
    }
};

// print data and random
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

// clone fn
Node *clone(Node *head)
{
    Node *next, *temp;
    for (Node *curr = head; curr != NULL;)
    {
        next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
    {
        curr->next->random = (curr->random != NULL) ? (curr->random->next) : NULL;
    }

    Node *original = head, *copy = head->next;

    temp = copy;

    while (original && copy)
    {
        original->next =
            original->next ? original->next->next : original->next;

        copy->next = copy->next ? copy->next->next : copy->next;
        original = original->next;
        copy = copy->next;
    }

    return temp;
}

// Driver code
int main()
{
    // create linked list
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    // given list
    cout << "Original list : \n";
    print(head);

    // cloned list
    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);
}
