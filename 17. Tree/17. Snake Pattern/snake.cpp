/*
    Print snake pattern i.e. first level from left to right,
    second level from right to left and so on

    eg:
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7

    output: 1 3 2 4 5 6 7
*/

#include <bits/stdc++.h>
using namespace std;

// Tree structure
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
    snake pattern printing

    Algorithm:
        Maintain a stack (to print in reverse order) and a
        rev variable (to toggle after each reverse print)

        Do a level order traversal

        For each level if rev is true put each node of this
        level in stack and print it one by one then toggle rev

*/
void printSpiral(Node *root)
{
    if (root != NULL)
    {
        // queue to print in level order
        queue<Node *> container;
        container.push(root);

        // to handle rev ec
        stack<int> stk;
        bool rev = false;

        // print logic:
        while (!container.empty())
        {
            int size = container.size();

            for (int i = 0; i < size; i++)
            {
                Node *curr = container.front();

                container.pop();

                /*
                    check if to print rev or normal
                */
                if (rev)                 // ec
                    stk.push(curr->key); // ec
                else
                    cout << curr->key << " ";

                if (curr->left != NULL)
                    container.push(curr->left);
                if (curr->right != NULL)
                    container.push(curr->right);
            }

            // if rev is true print ec
            if (rev)
            {
                while (stk.empty() == false)
                {
                    cout << stk.top() << " ";
                    stk.pop();
                }
            }

            // toggle rev ec
            rev = !rev;

            // if line break is required
            cout << endl;
        }
    }
}

// Driver code
int main()
{
    /*
                1
              /   \
             2     3
            / \   /  \
           4   5 6    7
    */
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    // fn call
    printSpiral(root);
}
