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
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right = new Node(60);
    root->right->left = new Node(50);
    root->right->right = new Node(70);
}