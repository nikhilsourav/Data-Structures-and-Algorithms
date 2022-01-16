/*

        10
       /  \
    20    30
         /  \
        40   50

    postorder (10)
    |
    |-> postorder (20)
    |   |
    |   |-> postorder (NULL)
    |   |
    |   |-> postorder (NULL)
    |   |
    |   |-> print (20)
    |
    |-> postorder (30)
    |   |
    |   |-> postorder (40)
    |   |   |
    |   |   |-> postorder (NULL)
    |   |   |
    |   |   |-> postorder (NULL)
    |   |   |
    |   |   |-> print (40)
    |   |
    |   |-> postorder (50)
    |   |
    |   |   |
    |   |   |-> postorder (NULL)
    |   |   |
    |   |   |-> postorder (NULL)
    |   |   |
    |   |   |-> print (50)
    |   |
    |   |-> print (30)
    |
    |-> print (10)

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

// Print postorder Time: O(n), Auxiliary Space: O(h)
void postorder(Node *root)
{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << root->key << " ";
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

    // output
    postorder(root);
}