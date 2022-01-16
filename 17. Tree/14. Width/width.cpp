/*
    Maximum width of binary tree

    eg:

           10
          /  \
         5    30
        /    /  \
       17   15   20

    output: 3
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
        left = right = NULL;
    }
};

// Max width of any level in binary tree
int width(Node *root)
{
    // corner case
    if (root == NULL)
        return 0;

    // Init queue
    queue<Node *> container;
    container.push(root);

    // init vars
    int res = 0;

    // logic
    while (!container.empty())
    {
        // update res
        int counter = container.size();
        res = max(res, counter);

        // further process
        for (int i = 0; i < counter; i++)
        {
            // take out a node
            Node *curr = container.front();

            // delete it
            container.pop();

            // enqueue its children
            if (curr->left != NULL)
                container.push(curr->left);
            if (curr->right != NULL)
                container.push(curr->right);
        }
    }

    // answer
    return res;
}

// Driver code
int main()
{
    /*
            10
          /   \
         5    30
             /  \
           15   20
    */
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(30);
    root->right->left = new Node(15);
    root->right->right = new Node(20);

    // fn call
    cout << width(root);
}