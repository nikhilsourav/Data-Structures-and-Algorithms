/*
    Given inorder and preorder traversal of a tree,
    construct a binary tree out of it

    in[] = [40, 20, 50, 10, 30, 80, 70, 90]
    pr[] = [10, 20, 40, 50, 30, 70, 80, 90]

    output:
                10
               /  \
              20   30
             /  \    \
            40   50   70
                     /  \
                    80  90

    We can only construct a binary tree only when inorder and
    one more traversal is given i.e. (in + pre) or (in + post)

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

// Inorder traversal
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
    }
}

// Time: O(n^2), can be reduced to O(n) by hashing and preprocessing
int preIndex = 0;
Node *constructTree(int in[], int pre[], int low, int high)
{
    // base case for leaf node
    if (low > high)
        return NULL;

    // create new root node from pre[]
    Node *root = new Node(pre[preIndex++]);

    // find this value in in[]
    int inIndex;
    for (int i = low; i <= high; i++)
    {
        if (in[i] == root->key)
        {
            inIndex = i;
            break;
        }
    }

    // construct left and right subtree out of this node
    root->left = constructTree(in, pre, low, inIndex - 1);
    root->right = constructTree(in, pre, inIndex + 1, high);

    return root;
}

// Driver code
int main()
{

    // inorder and preorder of tree
    int in[] = {20, 10, 40, 30, 50};
    int pre[] = {10, 20, 30, 40, 50};
    int n = sizeof(in) / sizeof(in[0]);

    // fn call
    Node *root = constructTree(in, pre, 0, n - 1);
    inorder(root);
}