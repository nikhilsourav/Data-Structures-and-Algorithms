/*
    Given a normal linked list with extra random pointers

    eg List: 1->2->3->4->5
    random link 1->3
    random link 2->4
    random link 3->1
    random link 4->3
    random link 5->4

    Clone this list and return its head
*/

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

// Print data and random
void print(Node *start)
{
    Node *ptr = start;
    while (ptr)
    {
        cout << "Data = " << ptr->data << ", Random  = " << ptr->random->data << endl;
        ptr = ptr->next;
    }
}

// Clone function
Node *clone(Node *head)
{
    // init nodes
    Node *next, *temp;

    for (Node *curr = head; curr != NULL;)
    {
        next = curr->next;
        curr->next = new Node(curr->data);
        curr->next->next = next;
        curr = next;
    }
    for (Node *curr = head; curr != NULL; curr = curr->next->next)
        curr->next->random = (curr->random != NULL) ? (curr->random->next) : NULL;

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

    // result
    return temp;
}

// Driver code
int main()
{
    // Create linked list
    Node *head = new Node(10);
    head->next = new Node(5);
    head->next->next = new Node(20);
    head->next->next->next = new Node(15);
    head->next->next->next->next = new Node(20);

    // Create random links in this linked list
    head->random = head->next->next;
    head->next->random = head->next->next->next;
    head->next->next->random = head;
    head->next->next->next->random = head->next->next;
    head->next->next->next->next->random = head->next->next->next;

    // Given list
    cout << "Original list : \n";
    print(head);

    // Cloned list
    cout << "\nCloned list : \n";
    Node *cloned_list = clone(head);
    print(cloned_list);
}
