/*
    Given a binary tree, find the maximum path sum.
    The path may start and end at any node in the tree.

        10
       /  \
      2   -25
     / \  /  \
    20 1  3  4

    output: 32 (10+2+20)
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int key)
    {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

// Global variable
int maxim;

// Find sum of nodes
int findSum(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // left and right sum
    int l = findSum(root->left);
    int r = findSum(root->right);

    // ignore negative sum
    if (l <= 0)
        l = 0;
    if (r <= 0)
        r = 0;

    // update maxim
    maxim = max(maxim, root->key + l + r);

    // return
    return root->key + max(l, r);
}

// Given function
int findMaxSum(Node *root)
{
    // init maxim
    maxim = INT_MIN;

    // fn call
    findSum(root);

    // result
    return maxim;
}

// Driver code
int main()
{
    /*

            10
           /  \
          2   -25
         / \  /  \
        20 1  3  4

    */
    Node *root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(-25);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->left = new Node(3);
    root->right->right = new Node(4);

    // fn call
    cout << findMaxSum(root);
}