/*
    For any node the value of sum of its left and right child
    must be equal to the value of this node

    eg:
        10
       /  \
      8    2
          /
         2
    
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

// Check if sum of children is equal to its parent
bool childSum(Node *root)
{
    // base condition
    if (root == NULL)
        return true;

    // if it is leaf node 
    if (root->left == NULL && root->right == NULL)
        return true;

    // init sum
    int sum = 0;

    // add root->left->key to sum
    if (root->left != NULL)
        sum += root->left->key;

    // add root->right->key to sum
    if (root->right != NULL)
        sum += root->right->key;

    // check current node's key == sum and recur for left subtree and right subtree
    return (root->key == sum && childSum(root->left) && childSum(root->right));
}

// Driver code
int main()
{
    /*
           20
          /  \
         8    12
             /  \
            3    9
    */
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->right->left = new Node(3);
    root->right->right = new Node(9);

    cout << boolalpha << childSum(root);
}