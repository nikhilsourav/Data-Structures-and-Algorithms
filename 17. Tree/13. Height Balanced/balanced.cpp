/*
    Height balanced means the difference between height
    of left subtree and right subtree should not be more
    than 1 and this should be true for every node

    eg:

           10
          /  \
         5    30
             /  \
           15   20

    output: true
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

// Find height
int height(Node *root)
{
    if (root == NULL)
        return 0;
    else
        return (1 + max(height(root->left), height(root->right)));
}

// Check balanced (diff between node <= 1)
bool isBalanced(Node *root)
{
    // base case
    if (root == NULL)
        return true;

    // left height
    int lh = height(root->left);
    // right height
    int rh = height(root->right);

    // check balanced for current node and recur for left subtree and right subtree
    return (abs(lh - rh) <= 1) and (isBalanced(root->left) && isBalanced(root->right));
}

/*
    efficient O(n)

    Algorithm
        For each node call isBalanced() for left subtree
        and right subtree.

        isBalance() will return height only if that subtree
        is balanced otherwise it will return -1
*/
int isHeightBalanced(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // check for left height
    int lh = isHeightBalanced(root->left);
    if (lh == -1)
        return -1;

    // check for right height
    int rh = isHeightBalanced(root->right);
    if (rh == -1)
        return -1;

    // condition for balanced tree
    if (abs(lh - rh) > 1)
        return -1;

    // returnheight
    else
        return max(lh, rh) + 1;
}

// Driver code
int main()
{
    /*
           10
          /  \
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
    cout << boolalpha << isBalanced(root) << "\n";
    isHeightBalanced(root) ? cout << "true" : cout << "false";
}