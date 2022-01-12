/*
    Find height of binary tree

    eg:
           10
          /  \
        20   30
            /  \
           40   50

    output: height = 3
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
        left = NULL;
        right = NULL;
    }
};

// Find height Time: O(n) Auxiliary Space: O(h)
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return 1 + max(height(root->left), height(root->right));
}

// Driver code
int main()
{
    /*
            10
          /  \
        20   30
            /  \
           40   50
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // print height of tree
    cout << height(root);
}