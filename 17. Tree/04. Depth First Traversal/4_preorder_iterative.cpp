/*
    Iterative preorder traversal

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
    Similar to breadth first traversal, difference is
    we use stack and push right child first

    Algorithm:
        1. Maintain a stack which gives access to last visited node

        2. Do this while (!stk.empty())

            a.  Take out a node, print it, pop it

            b.  Push children if possible into stack
*/
void preorder(Node *root)
{
    // corner case
    if (root == NULL)
        return;

    // init stack
    stack<Node *> stk;
    stk.push(root);

    // logic:
    while (!stk.empty())
    {
        // take out a node
        Node *curr = stk.top();

        // print it
        cout << curr->key << " ";

        // pop it
        stk.pop();

        // push children if possible
        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);
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
    preorder(root);
}