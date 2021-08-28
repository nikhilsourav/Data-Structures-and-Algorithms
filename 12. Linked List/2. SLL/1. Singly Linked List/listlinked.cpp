/*
    abbr: 
        node_struct => node using structure
        node_class => node using class
        head_struct => head pointer created using struct
        head_class => head pointer created using class
*/
#include <bits/stdc++.h>
using namespace std;

// Node_struct without constructor using structure
struct Node_struct
{
    int data;
    Node_struct *next;
};

// print likedlist for structure Node_struct
void printList(Node_struct *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Node_class with constructor using class
class Node_class
{
public:
    int data;
    Node_class *next;
    Node_class(int x)
    {
        data = x;
        next = NULL;
    }
};

// print likedlist for class Node_class
void printList(Node_class *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout << "\n";
}

// Driver code
int main()
{
    // ======================= Using structure ======================== //

    // create three pointers
    Node_struct *head_struct = NULL;
    Node_struct *second_struct = NULL;
    Node_struct *third_struct = NULL;

    // initialize three Node
    head_struct = new Node_struct();
    second_struct = new Node_struct();
    third_struct = new Node_struct();

    // fill data
    head_struct->data = 10;
    second_struct->data = 20;
    third_struct->data = 30;

    // link them
    head_struct->next = second_struct;
    second_struct->next = third_struct;
    third_struct->next = NULL; // not needed third_struct is already NULL (initialization)

    // print list
    printList(head_struct);

    // ======================= Using class ======================== //

    // create Node and assign data using constructor
    Node_class *head_class_1 = new Node_class(100);
    Node_class *second_class_1 = new Node_class(200);
    Node_class *third_class_1 = new Node_class(300);

    // link them
    head_class_1->next = second_class_1;
    second_class_1->next = third_class_1;
    third_class_1->next = NULL; // not needed third_class_1 already points to NULL (constructor)

    // print
    printList(head_class_1);

    // ======================= Short implementation class ======================== //

    // create Node and assign data using constructor
    Node_class *head_class_2 = new Node_class(1000);

    // link subsequent nodes
    head_class_2->next = new Node_class(2000);
    head_class_2->next->next = new Node_class(3000);

    // print
    printList(head_class_2);
}