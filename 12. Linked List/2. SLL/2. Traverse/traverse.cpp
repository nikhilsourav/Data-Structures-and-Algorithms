#include <bits/stdc++.h>
using namespace std;

// Node using class
class Node
{
public:
    // data
    int data;

    // Node pointer
    Node *next;

    // constructor
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// print using iteration
void itrPrint(Node *ptr)
{
    // print logic
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

// print using recursion
void recPrint(Node *ptr)
{
    // base case
    if (ptr == NULL)
        return;

    // print data
    cout << ptr->data << " ";

    // call for next
    return recPrint(ptr->next);
}

// Driver code
int main()
{
    // create a new linked list
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    // fn call
    itrPrint(head);
    cout << "\n";
    recPrint(head);
}

/*
    => The pointer (*ptr) in print() and the pointer (*head) in main are diff.
    => If we change pointer to refer to something else, This change won't occur.
    => But if we change value. It will reflect.

    eg: 
        ptr++ will not change address stored in
        *ptr = 30 will change head value 
    
    eg:
        => consider a list with only one value = 10

            +---+---+
            | 10 | o------>NULL
            +---+---+	
        
        => if we print this list with printList() fn twice like this:

            printList(head);
            printList(head);

        => we may think that in the first fn call the head pointer becomes NULL
           so it won't print the second time

        => But turns out thats not the case! Since the pointer of main and pointer
           of printList() fn are different, each time the 'head' (of main) is copied
           to the pointer 'ptr' of  printList() fn, so the original 'head' of main fn 
           is not modified.
*/