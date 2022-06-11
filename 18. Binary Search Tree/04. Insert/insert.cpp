/*
    Given root of a binary search tree and a key,
    Insert this at its correct position. If key already
    exist do nothing

    eg:

        15
       /  \
      5    20
     /    /  \
    3    18   80
        /
       16

    key 19
    output:

        15
       /  \
      5    20
     /    /  \
    3    18   80
        /  \
       16   19
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

// Insert iterative
Node *insertIterative(Node *root, int val)
{
    // if root is NULL create new node and return
    if (root == NULL)
    {
        Node *newNode = new Node(val);
        return newNode;
    }

    // get hold of parent root and iterate
    Node *curr = root;
    while (curr != NULL)
    {
        // if val already exist simply return
        if (curr->key == val)
            return root;

        // go right
        if (curr->key < val)
        {
            // if curr->right doesnt exist insert here
            if (curr->right == NULL)
            {
                curr->right = new Node(val);
                return root;
            }

            // otherwise continue traversal
            curr = curr->right;
        }

        // go left
        else
        {
            // if curr->left doesnt exist insert here
            if (curr->left == NULL)
            {
                curr->left = new Node(val);
                return root;
            }

            // otherwise continue traversal
            curr = curr->left;
        }
    }

    // default return
    return root;
}

// Insert recursive
Node *insertRecursive(Node *root, int val)
{
    // base case
    if (root == NULL)
        return new Node(val);

    // go right
    if (root->key < val)
        root->right = insertRecursive(root->right, val);

    // go left
    else if (root->key > val)
        root->left = insertRecursive(root->left, val);

    // default
    return root;
}

// print tree
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}

// Driver code
int main()
{
    // Given tree
    Node *root = new Node(15);
    root->left = new Node(5);
    root->left->left = new Node(3);
    root->right = new Node(20);
    root->right->left = new Node(18);
    root->right->left->left = new Node(16);
    root->right->right = new Node(80);
    int val = 19;

    print(root);

    // fn call
    root = insertIterative(root, val);
    root = insertRecursive(root, val);

    cout << endl;
    print(root);
}