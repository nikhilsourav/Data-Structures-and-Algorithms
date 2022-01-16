/*
    Level order traversal of binary tree using queue

    eg:
            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80

    output: 10 20 30 40 50 60 70
    https://www.youtube.com/watch?v=86g8jAQug04
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

/*
    Time: O(n), Auxiliary Space O(n) or O(width)

    1. Visit a node and keep ref of all it's child in queue

    2. As long as queue is not empty do this:
        
        a.  Take out a node
        b.  Print it
        c.  Push it's children in queue
*/
void levelOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        // initialize queue with root
        queue<Node *> qu;
        qu.push(root);

        // logic
        while (!qu.empty())
        {
            // take out a node
            Node *curr = qu.front();

            // print it
            cout << curr->key << " ";

            // delete from queue
            qu.pop();

            // push children if possible
            if (curr->left != NULL)
                qu.push(curr->left);
            if (curr->right != NULL)
                qu.push(curr->right);
        }
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

    // print items in level order
    levelOrderTraversal(root);
}