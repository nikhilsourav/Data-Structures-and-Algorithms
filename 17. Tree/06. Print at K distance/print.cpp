/*
    Print all nodes at a distance k from top (top is at distance 0)

    eg:
            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80

    k = 2
    output: 40 50 70
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

// Time: O(n) Auxiliary Space: O(h)
void print(Node *root, int k)
{
    if (root != NULL)
    {
        print(root->left, k - 1);
        if (k == 0)
            cout << root->key << " ";
        print(root->right, k - 1);
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
    int k = 2;

    // output
    print(root, k);
}