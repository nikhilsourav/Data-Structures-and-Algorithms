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

    the size of queue at each point represents the
    number of nodes at that level
*/
void levelOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        // init queue with root
        queue<Node *> qu;
        qu.push(root);

        // logic:
        while (!qu.empty())
        {
            // get current level size
            int size = qu.size();

            // print all node in current level
            for (int i = 0; i < size; i++)
            {
                // take out first element of queue
                Node *curr = qu.front();

                // delete it from queue
                qu.pop();

                // print it
                cout << curr->key << " ";

                // push children if possible
                if (curr->left != NULL)
                    qu.push(curr->left);
                if (curr->right != NULL)
                    qu.push(curr->right);
            }

            // new line after current level
            cout << "\n";
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