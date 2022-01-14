/*
    Find maximum value in a binary tree

    eg:

            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80
    output: 80
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

// Maximum value in tree
int getMax(Node *root)
{
    if (root == NULL)
        return INT_MIN;
    return max(root->key, max(getMax(root->left), getMax(root->right)));
}

// Driver code
int main()
{
    /*
            20
           /  \
         80   30
             /  \
           40   50
    */

    Node *root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // fn call
    cout << getMax(root);
}