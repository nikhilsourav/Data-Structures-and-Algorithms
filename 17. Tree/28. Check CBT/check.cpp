/*
    Given a Binary Tree, check whether the given Binary Tree
    is Complete Binary Tree or not. A complete binary tree
    is a binary tree in which every level, except possibly
    the last, is completely filled, and the last level must
    be filled from left to right

    eg:

           1
         /   \
        2     3

    output: true
           1
         /   \
        2     3
         \   /  \
          4 5    6

    output: false
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

// Traverse
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}

// Check CBT
bool isCBT(Node *root)
{
    // corner case
    if (!root)
        return true;

    // init queue
    queue<Node *> qu;
    qu.push(root);

    // init falg
    bool flag = false;

    // logic:
    while (!qu.empty())
    {
        // if left exist
        if (qu.front()->left)
        {
            // and flag is false
            if (flag)
                return false;
            // push left
            else
                qu.push(qu.front()->left);
        }
        // if left doesn't exist
        else
            flag = true;

        // if right exist
        if (qu.front()->right)
        {
            // and flag is false
            if (flag)
                return false;
            // push right
            else
                qu.push(qu.front()->right);
        }

        // if right doesn't exist
        else
            flag = true;

        // update queue
        qu.pop();
    }
    return true;
}

// Driver code
int main()
{
    /*

           1
         /   \
        2     3
         \   /  \
          4 5    6
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(5);
    root->right->right = new Node(6);

    // fn call
    cout << boolalpha << isCBT(root);
}