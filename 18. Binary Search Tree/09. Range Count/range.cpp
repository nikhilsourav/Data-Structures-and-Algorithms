/*
    Given a Binary Search Tree (BST) and a range l-h (inclusive),
    count the number of nodes in the BST that lie in the given range.

        10
       /  \
      5    50
     /    /  \
    1    40  100

    l = 5, h = 45

    Output: 3
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

// Global vector to store result
int cnt;

// Traverse, check range and increment count
void inorder(Node *root, int l, int h)
{
    if (root != NULL)
    {
        inorder(root->left, l, h);

        if (root->key >= l && root->key <= h)
            cnt++;

        inorder(root->right, l, h);
    }
}

// Given function
int getCount(Node *root, int l, int h)
{
    cnt = 0;
    inorder(root, l, h);
    return cnt;
}

// Driver code
int main()
{
    /*

            40
           /  \
          20   60
         / \   / \
        10 30 50 70

    */
    Node *root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    int l = 30, r = 70;

    // fn call
    cout << getCount(root, l, r);
}