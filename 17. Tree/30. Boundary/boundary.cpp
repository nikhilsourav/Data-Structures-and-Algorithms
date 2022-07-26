/*
    https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1

    Input:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
      / \
     8   9

    Output: 1 2 4 8 9 6 7 3
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// Left
void traverseLeft(Node *root, vector<int> &res)
{
    // base case
    if (root == NULL)
        return;

    // no need to push leaf node
    if (root->left == NULL && root->right == NULL)
        return;

    res.push_back(root->data);

    if (root->left)
        traverseLeft(root->left, res);
    else
        traverseLeft(root->right, res);
}

// Leaf
void traverseLeaf(Node *root, vector<int> &res)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        res.push_back(root->data);
    traverseLeaf(root->left, res);
    traverseLeaf(root->right, res);
}

// Right
void traverseRight(Node *root, vector<int> &res)
{
    // base case
    if (root == NULL)
        return;

    // no need to push leaf node
    if (root->left == NULL && root->right == NULL)
        return;

    if (root->right)
        traverseRight(root->right, res);
    else
        traverseRight(root->left, res);

    // need right traversal in rev ordre
    res.push_back(root->data);
}

// Return boundary traversal of tree
vector<int> boundary(Node *root)
{
    vector<int> res;
    res.push_back(root->data);

    traverseLeft(root->left, res);
    traverseLeaf(root->left, res);
    traverseLeaf(root->right, res);
    traverseRight(root->right, res);

    return res;
}

// Driver code
int main()
{
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
           / \
          8   9

    */

    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->left->right->left = new Node(8);
    root->left->right->right = new Node(9);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> res = boundary(root);

    for (auto data : res)
        cout << data << " ";
}