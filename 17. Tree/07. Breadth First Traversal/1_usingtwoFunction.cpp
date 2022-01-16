/*
    Level order traversal of binary tree using two functions

    eg:
            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80
    
    output: 10 20 30 40 50 60 70
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

// Height of tree Time: O(n) Auxiliary Space: O(h)
int height(Node *root)
{
    if (root == NULL)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Time: O(n) Space: O(h)
void levelOrderTraversal(Node *root, int k)
{
    if (root != NULL)
    {
        levelOrderTraversal(root->left, k - 1);
        if (k == 0)
            cout << root->key << " ";
        levelOrderTraversal(root->right, k - 1);
    }
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
    root->right->right = new Node(70);
    root->right->right->right = new Node(80);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // find height and print node at each height
    int h = height(root);
    for (int i = 0; i <= h; i++)
        levelOrderTraversal(root, i);
}