/*
    Given root of a binary tree, convert it into its mirror

        10                  10
       /  \     (mirror)   /  \
      20   30      =>     30   20
     /  \                     /  \
    40  60                   60  40
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

/*
    Algorithm:
        Swap every node's left and right pointer recursively
*/
void mirror(Node *root)
{
    if (root == NULL)
        return;

    mirror(root->left);
    mirror(root->right);

    swap(root->left, root->right);
}

// Print tree
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Driver code
int main()
{
    // Given trees
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(60);

    // fn call
    mirror(root);
    inorder(root);
}