/*
    Iterative postorder traversal

        10
       /  \
      20   30
     /  \
    40  50

    output: 40 50 20 30 10
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

        2. Maintain another stack to print output

        3. Do this while(!stk.empty())

            a. Take out a node, store it in output stack, pop it

            b. Push children if possible
*/
void postorder(Node *root)
{
    // corner case
    if (root == NULL)
        return;

    // init stack
    stack<Node *> stk;
    stk.push(root);

    // output stack
    stack<int> res;

    // logic:
    while (!stk.empty())
    {
        // take out a node
        Node *curr = stk.top();

        // instead of printing directly, store it
        res.push(curr->key);

        // pop it
        stk.pop();

        // push children if possible
        if (curr->left)
            stk.push(curr->left);
        if (curr->right)
            stk.push(curr->right);
    }

    // print postorder traversal
    while (!res.empty())
    {
        cout << res.top() << " ";
        res.pop();
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
    postorder(root);
}
