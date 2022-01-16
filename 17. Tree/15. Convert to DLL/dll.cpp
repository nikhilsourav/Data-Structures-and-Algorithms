/*
    Given a tree, convert it into a doubly linked list where
    the list items should be inorder traversal of the tree.

    eg:

            10
           /  \
          5    20
              /  \
             30   35

    output 5 <=> 10 <=> 30 <=> 20 <=> 35
*/

#include <bits/stdc++.h>
using namespace std;

// Tree node
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    Node(int k)
    {
        key = k;
        left = right = NULL;
    }
};

// Fn to print list
void printlist(Node *head)
{
    Node *curr = head;
    while (curr != NULL)
    {
        cout << curr->key << " ";
        curr = curr->right;
    }
    cout << endl;
}

/*
    Algorithm:
        Maintain a previous pointer

        Do inorder traversal of the tree and while traversing:

        If we see prev == NULL that means it is the first iteration
        so we need to explicitly set head = currRoot

        If prev != NULL this means it is the subsequent iteration
        so, set currRoot->left = prev and prev->right = currRoot

        Update prev = currRoot for further iterations
*/

// temporary pointer / previous pointer
Node *prevv = NULL;

// fn to convert binary tree to doubly linked list
Node *treeTolist(Node *root)
{
    // base case
    if (root == NULL)
        return root;

    /*
        process left subtree
    */
    Node *head = treeTolist(root->left);

    /*
        process current node
    */
    if (prevv == NULL)
    {
        head = root;
        prevv = root;
    }
    else
    {
        root->left = prevv;
        prevv->right = root;
        prevv = root;
    }

    /*
        process right subtree
    */
    treeTolist(root->right);

    // head of list for first call
    return head;
}

// Driver code
int main()
{
    /*
            10
           /  \
          5    20
              /  \
             30   35
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->right->left = new Node(30);
    root->right->right = new Node(35);

    // fn call
    Node *head = treeTolist(root);
    printlist(head);
}