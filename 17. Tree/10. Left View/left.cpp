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

    output: 10 20 40 80
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
    Left view of binary tree recursive

    Algorithm:
        Do a pre order traversal (root -> left -> right)

        For every level check if maxLevel < currLevel

        If yes => print key and update maxLevel
        If no => recur for left and right sub tree with updated level
*/

// Left view of binary tree recursive
int maxLevel = 0;
void printLeft(Node *root, int currLevel)
{
    if (root != NULL)
    {
        if (maxLevel < currLevel)
        {
            cout << root->key << " ";
            maxLevel = currLevel;
        }
        printLeft(root->left, currLevel + 1);
        printLeft(root->right, currLevel + 1);
    }
}

void leftView(Node *root)
{
    printLeft(root, 1);
}

// Left view of binary tree iterative
void printLeftView(Node *root)
{
    if (root != NULL)
    {
        // initialize Queue
        queue<Node *> qu;
        qu.push(root);

        // logic:
        while (!qu.empty())
        {
            // elements in 0 to qu.size() represent elements in each level
            int count = qu.size();

            // for all queue size
            for (int i = 0; i < count; i++)
            {
                // take out first item of queue
                Node *curr = qu.front();

                // if i is 0 i.e. first node of a level
                if (i == 0)
                    cout << curr->key << " ";

                // delete item from queue
                qu.pop();

                // push left and right if possible
                if (curr->left != NULL)
                    qu.push(curr->left);
                if (curr->right != NULL)
                    qu.push(curr->right);
            }

            // print newline
            cout << "\n";
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
    leftView(root);
    cout << endl;
    printLeftView(root);
}