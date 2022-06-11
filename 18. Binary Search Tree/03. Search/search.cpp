/*
    Given root of a binary search tree and a key,
    check whether this key is present in the tree or not

    eg:
    
        15
       /  \
      5    20
     /    /  \
    3    18   80
        /
       16

    key 20
    output: true
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

// Recursive search Time: O(h), Space: O(h)
bool searchRecursive(Node *root, int val)
{
    // if root is null or key not present
    if (root == NULL)
        return false;

    // if found
    if (root->key == val)
        return true;

    // go to right half
    else if (root->key < val)
        return searchRecursive(root->right, val);

    // go to left half
    else
        return searchRecursive(root->left, val);
}

// Iterative search, Time: O(h), Space: O(1)
bool searchIterative(Node *root, int val)
{
    // logic:
    while (root != NULL)
    {
        // if found
        if (root->key == val)
            return true;

        // go to right
        else if (root->key < val)
            root = root->right;
        // go to left
        else
            root = root->left;
    }

    // if root is null
    return false;
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
    int val = 16;

    // fn call
    cout << boolalpha << searchRecursive(root, val) << "\n";
    cout << boolalpha << searchIterative(root, val);
}