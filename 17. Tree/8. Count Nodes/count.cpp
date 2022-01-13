/*
    Count total number of nodes in a binary tree

    eg:

            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80
    output: 7
*/

#include <bits/stdc++.h>
using namespace std;

// Tree node
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

// Count all nodes in binary tree using global var works only once
int cnt = 0;
int countNodes(Node *root)
{
    if (root != NULL)
    {
        countNodes(root->right);
        countNodes(root->left);
        cnt++;
    }
    return cnt;
}

// Count all nodes in binary tree Time: O(n), Space: O(h)
int countNode(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + countNode(root->left) + countNode(root->right);
}

// Driver code
int main()
{
    /*
            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80
    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->right = new Node(60);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // fn call
    cout << countNodes(root) << "\n";
    cout << countNode(root) << "\n";
}

/*

         10
        /  \
       20  30
     /  \   \
    40  50  60

    countNode (10)
    |
    |-> countNode (20)
    |   |
    |   |-> countNode (40)
    |   |   |
    |   |   |-> countNode (NULL)
    |   |   |
    |   |   |-> countNode (NULL)
    |   |   
    |   |-> countNode (50)
    |       |
    |       |-> countNode (NULL)
    |       |
    |       |-> countNode (NULL)
    |
    |-> countNode (30)
        |
        |-> countNode (NULL)
        |
        |-> countNode (60)
            |
            |-> countNode (NULL)
            |
            |-> countNode (NULL)

    output: 6
*/