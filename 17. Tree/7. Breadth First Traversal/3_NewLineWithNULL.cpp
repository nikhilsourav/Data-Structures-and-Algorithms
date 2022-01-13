/*
    Level order traversal of binary tree using queue 
    with new line after each level

    eg:
            10
           /  \
         20   30
        /  \   \
       40  50  70
                \
                80
    
    output: 
    10 
    20 30 
    40 50 70
    80
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

    Idea:
        when we traverse the last node of a level,
        the next level is completely there in the queue

    Algorithm:
        when we traverse the current level completely,
        push a NULL marker into the queue

        when we see NULL next time, we're sure that our
        next level is completely there in the queue,
        so we can push a new NULL into the queue

        stop when queue size becomes 1 i.e. when there
        is only NULL in the queue
*/
void levelOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        // queue of type Node *
        queue<Node *> container;

        // push root and NULL
        container.push(root);
        container.push(NULL);

        // level order traversal
        while (container.size() != 1)
        {
            // take out current node
            Node *curr = container.front();

            // delete from queue
            container.pop();

            // if current node is null
            if (curr == NULL)
            {
                cout << "\n";
                container.push(NULL);
                continue;
            }

            // if current node is not null
            else
            {
                cout << curr->key << " ";
            }

            // push children
            if (curr->left != NULL)
                container.push(curr->left);
            if (curr->right != NULL)
                container.push(curr->right);
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