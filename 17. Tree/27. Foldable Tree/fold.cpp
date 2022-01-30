/*
    Given a binary tree, check if the tree can be folded or not.
    A tree can be folded if left and right subtrees of the tree
    are structure wise same. An empty tree is considered as foldable.

    Consider the below trees:
    (a) and (b) can be folded.
    (c) and (d) cannot be folded.


    (a)
           10
         /    \
        7      15
         \    /
          9  11
    (b)
            10
           /  \
          7    15
         /      \
        9       11
    (c)
            10
           /  \
          7   15
         /    /
        5   11
    (d)
             10
           /   \
          7     15
        /  \    /
       9   10  12

*/
#include <bits/stdc++.h>
using namespace std;

// Tree structure
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

// Function to check whether a binary tree is foldable or not.
bool helper(Node *n1, Node *n2)
{

    if (!n1 && !n2)
        return true;
    if (!n1 || !n2)
        return false;

    return helper(n1->left, n2->right) && helper(n1->right, n2->left);
}

// Given function
bool IsFoldable(Node *root)
{
    if (!root)
        return true;
    return helper(root->left, root->right);
}

// Driver code
int main()
{
    /*
             10
            /  \
           7    15
         /  \   /  \
        N   9  11   N
    */

    Node *root = new Node(10);
    root->left = new Node(7);
    root->left->right = new Node(9);
    root->right = new Node(15);
    root->right->left = new Node(11);

    // fn call
    cout << boolalpha << IsFoldable(root);
}