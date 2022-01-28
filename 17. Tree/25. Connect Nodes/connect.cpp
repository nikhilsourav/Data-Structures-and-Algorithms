/*
    For a particular level connect each node to the node right of it
    if there is no right node connect it to NULL

        10                    10------> NULL
       / \                   /  \
      3   5       =>        3--->5--------> NULL
     / \   \               / \    \
    4   1   2             4--->1-->2-------> NULL

    Given Node struct will have additional nextRight pointer.
    Initially, all the nextRight pointers point to garbage values.
    connect function should set these pointers to point next right for each node.

    // https://rb.gy/zvbjsd
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node *nextRight;
    Node(int key)
    {
        this->key = key;
        left = NULL;
        right = NULL;
    }
};

// Special traversal using nextRight pointer
void printSpecial(Node *root)
{
    if (root == NULL)
        return;

    Node *next_root = NULL;

    while (root != NULL)
    {
        cout << root->key << " ";

        if (root->left && (!next_root))
            next_root = root->left;
        else if (root->right && (!next_root))
            next_root = root->right;

        root = root->nextRight;
    }

    printSpecial(next_root);
}

// Normal inorder traversal
void inorder(Node *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->key << " ";
    inorder(root->right);
}

// Connect
void connect(Node *root)
{
    if (root != NULL)
    {
        // initialize queue with root
        queue<Node *> container;
        container.push(root);

        // logic
        while (!container.empty())
        {
            // get current level size
            int size = container.size();

            // loop for each level
            for (int i = 0; i < size; i++)
            {
                // take out a node
                Node *curr = container.front();

                // delete it from queue
                container.pop();

                // connext nextRight node
                Node *next = container.front();
                curr->nextRight = next;

                // connect last node to null
                if (i == size - 1)
                    curr->nextRight = NULL;

                // push children if possible
                if (curr->left != NULL)
                    container.push(curr->left);
                if (curr->right != NULL)
                    container.push(curr->right);
            }
        }
    }
}

// Driver code
int main()
{
    /*

      3
     / \
    1   2

      3-----> NULL
     / \
    1-->2-----> NULL

    */
    Node *root = new Node(3);
    root->left = new Node(1);
    root->right = new Node(2);

    // fn call
    connect(root);

    printSpecial(root);
    cout << "\n";
    inorder(root);
}