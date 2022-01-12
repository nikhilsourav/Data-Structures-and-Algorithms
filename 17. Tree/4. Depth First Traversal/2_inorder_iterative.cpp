/*
    Iterative inorder traversal

        10
       /  \
      20   30
     /  \
    40  50

    output: 40 20 50 10 30
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

/*
    Algorithm:
        1. Maintain a stack which gives access to last visited node

        2. Do this while(root != NULL or stk.empty() == false):

            a.  Start from root (current node), go left and push every
                node in the stack while root != NULL

            b.  When NULL is encountered, take out an element from stack
                print it, pop it and visit right
*/
void inorder(Node *root)
{
    // corner case
    if (root == NULL)
        return;

    // init stack
    stack<Node *> stk;

    // logic:
    while (root != NULL or stk.empty() == false)
    {
        // go left
        while (root != NULL)
        {
            stk.push(root);
            root = root->left;
        }

        // take out node
        root = stk.top();

        // print it
        cout << root->key << " ";

        // delete from stack
        stk.pop();

        // visit right
        root = root->right;
    }
}

// Driver code
int main()
{
    /*

            10
           /  \
          20   30
         / \   /
        40 50 60

    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    // fn call
    inorder(root);
}