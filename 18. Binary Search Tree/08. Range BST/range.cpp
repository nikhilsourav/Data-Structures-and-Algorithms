/*
    Given a Binary Search Tree and a range [low, high].
    Find all the numbers in the BST that lie in the given range.

        17
       /  \
      4    18
     /  \
    2    9

    l = 4, h = 24

    output: 4 9 17 18
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
vector<int> res;

// Traverse, check range and push in result vector
void inorder(Node *root, int low, int high)
{
    if (root != NULL)
    {
        inorder(root->left, low, high);

        if (root->key >= low && root->key <= high)
            res.push_back(root->key);

        inorder(root->right, low, high);
    }
}

// Given function
vector<int> printNearNodes(Node *root, int low, int high)
{
    inorder(root, low, high);
    return res;
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
    vector<int> arr = printNearNodes(root, l, r);
    for (auto x : arr)
        cout << x << " ";
}