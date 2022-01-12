/*

        10
       /  \
    20    30
         /  \
        40   50

    preorder (10)
    |
    |-> print (10)
    |   
    |-> preorder (20)
    |   |
    |   |-> print (20)
    |   |
    |   |-> preorder (NULL)
    |   |
    |   |-> preorder (NULL)
    |
    |-> preorder (30)
        |
        |-> print (30)
        |   
        |-> preorder (40)
        |   |
        |   |-> print (40)
        |   |
        |   |-> preorder (NULL)
        |   |
        |   |-> preorder (NULL)
        |
        |-> preorder (50)
            |
            |-> print (50)
            |
            |-> preorder (NULL)
            |
            |-> preorder (NULL)

    output: 10 20 30 40 50
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
        left = NULL;
        right = NULL;
    }
};

// Print preorder Time: O(n), Auxiliary Space: O(h)
void preorder(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

// Driver code
int main()
{
    // Given tree
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);

    // fn call
    preorder(root);
}