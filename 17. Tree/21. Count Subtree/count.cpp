/*
    Given a binary tree and an integer X.
    Find the count of number of subtree having
    total node’s data sum equal to the value X.

         5
       /   \
     -10    3
     / \   / \
    9   8 -4  7


      -10
     /   \     7
    9     8

    output: 2
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
int cnt, target;

// Find sum of nodes
int findSum(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // current sum
    int currSum = root->key + findSum(root->left) + findSum(root->right);

    // check
    if (currSum == target)
        cnt++;

    // return
    return currSum;
}

// Given function
int countSubtreesWithSumX(Node *root, int X)
{
    // initialize global vars
    cnt = 0;
    target = X;

    // call fn
    findSum(root);

    // result
    return cnt;
}

// Driver code
int main()
{
    /*

            5
           /  \
         -10   3
         / \   / \
        9   8 -4  7

    */
    Node *root = new Node(5);
    root->left = new Node(-10);
    root->right = new Node(3);
    root->left->left = new Node(9);
    root->left->right = new Node(8);
    root->right->left = new Node(-4);
    root->right->right = new Node(7);

    // fn call
    int X = 7;
    cout << countSubtreesWithSumX(root, X);
}
