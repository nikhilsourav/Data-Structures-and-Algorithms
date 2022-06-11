/*
    Given a binary tree, we need to find sum of nodes in all
    vertical lines starting from leftmost line to rightmost.

        40
       /  \
      20   60
     / \   / \
    10 30 50 70

    output: 10 20 120 60 70 
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

// Helper function (offset = horizontal distance)
void vertical(Node *root, int offset, map<int, int> &mp)
{
    if (root == NULL)
        return;

    vertical(root->left, offset - 1, mp);
    mp[offset] += root->key;
    vertical(root->right, offset + 1, mp);
}

// Vertical sum
vector<int> verticalSum(Node *root)
{
    // init
    int offset = 0;
    map<int, int> mp;

    // fn call
    vertical(root, offset, mp);

    // answer vector
    vector<int> res;
    for (auto pair : mp)
        res.push_back(pair.second);

    // answer
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

    // fn call
    vector<int> ans = verticalSum(root);
    for (auto &val : ans)
        cout << val << " ";
}