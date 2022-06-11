/*
    Given a binary floor tree and a key, find the value
    if it exists otherwise find closest smaller value

    eg:

          10
         /  \
        5   15
           /  \
          12  30

    key = 14
    output: 12

    key = 4
    output: NULL

    key = 30
    output: 30

    key = 100
    output: 100

    Three cases arise when we visit a node:
    1. If the root matches with givenKey => return root 
    2. If root > givenKey =>
        move left
    3. If root < givenKey => 
        store this root as potential ans and move right
    
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

// Find floor value of a number or the number itself if exist
Node *floor(Node *root, int val)
{
    // logic:
    Node *res = NULL;
    while (root != NULL)
    {
        // case 1: if found
        if (root->key == val)
            return root;

        // case 2: go to left
        else if (root->key > val)
            root = root->left;
        // case 3: update and go to right
        else
        {
            res = root;
            root = root->right;
        }
    }

    // result
    return res;
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
    int val = 17;

    // fn call
    Node *temp = floor(root, val);
    cout << temp->key << " ";
}