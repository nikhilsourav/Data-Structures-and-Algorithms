/*
    Print left view of binary tree

    eg:

            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80

    output: 10 30 70 80
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

/*
    Right view of binary tree recursive

    Algorithm:
        Do a traversal (root -> right -> left)

        For every level check if maxLevel < currLevel

        If yes => print key and update maxLevel
        If no => recur for left and right sub tree with updated level
*/

// Right view of binary tree recursive
int maxLevel = 0;
void printRight(Node *root, int currLevel)
{
    if (root != NULL)
    {
        if (maxLevel < currLevel)
        {
            cout << root->key << " ";
            maxLevel = currLevel;
        }
        printRight(root->right, currLevel + 1);
        printRight(root->left, currLevel + 1);
    }
}

void rightView(Node *root)
{
    printRight(root, 1);
}

// Right view of binary tree iterative
void printRighView(Node *root)
{
    if (root != NULL)
    {
        // initialize Queue
        queue<Node *> qu;
        qu.push(root);

        // logic:
        while (!qu.empty())
        {
            // queue size
            int count = qu.size();

            // for all queue size
            for (int i = 0; i < count; i++)
            {
                // take out first item of queue
                Node *curr = qu.front();

                // if i is last i.e. last node of a level
                if (i == count - 1)
                    cout << curr->key << " ";

                // delete item from queue
                qu.pop();

                // push left and right if possible
                if (curr->left != NULL)
                    qu.push(curr->left);
                if (curr->right != NULL)
                    qu.push(curr->right);
            }
        }
    }
}

// Driver code
int main()
{
    /*
            20
           /  \
         80   30
             /  \
           40   50
                 \
                 60
    */
    Node *root = new Node(20);
    root->left = new Node(80);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(50);
    root->right->right->right = new Node(60);

    // fn call
    rightView(root);
    cout << endl;
    printRighView(root);
}