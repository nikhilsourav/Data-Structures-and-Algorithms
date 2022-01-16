/*

       10
      /  \
    20    30
         /  \
        40   50

    inorder (10)
    |
    |-> inorder (20)
    |   |
    |   |-> inorder (NULL)
    |   |
    |   |-> print (20)
    |   |
    |   |-> inorder (NULL)
    |
    |-> print (10)
    |
    |-> inorder (30)
        |
        |-> inorder (40)
        |   |
        |   |-> inorder (NULL)
        |   |
        |   |-> print (40)
        |   |
        |   |-> inorder (NULL)
        |
        |-> print (30)
        |
        |-> inorder (50)
            |
            |-> inorder (NULL)
            |
            |-> print (50)
            |
            |-> inorder (NULL)

    output: 20 10 40 30 50
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

// Print inorder Time: O(n), Auxiliary Space: O(h)
void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        cout << root->key << " ";
        inorder(root->right);
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
    inorder(root);
}