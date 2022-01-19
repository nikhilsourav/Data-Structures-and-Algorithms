/*
    Diameter is number of nodes on the longest path between two leaf nodes

    eg:

            10
           /  \
          20   30
              /  \
             40   50
            /
           60

    output: 5
    longest path 20 -> 10 -> 30 -> 40 -> 60

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
    Find diameter Time: O(n^2)

    Algorithm:

        For every node (consider it as root) find leftHeight,
        rightHeight and add 1 (root itself)

        Find maximum of this for every node
*/

int height(Node *root)
{
    if (root == NULL)
        return 0;
    return (1 + max(height(root->left), height(root->right)));
}

int diameter(Node *root)
{
    // base case
    if (root == NULL)
        return 0;

    // compute diameter
    int diamOfRoot = 1 + height(root->left) + height(root->right);
    int diamOfLeft = diameter(root->left);
    int diamOfRight = diameter(root->right);

    // find max
    return max({diamOfRoot, diamOfLeft, diamOfRight});
}

/*
    Optimized diameter
*/
int res = INT_MIN;
int diameterOptimized(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = diameterOptimized(root->left);
    int rh = diameterOptimized(root->right);

    res = max(res, lh + rh + 1);

    return 1 + max(lh, rh);
}

// Driver code
int main()
{
    // Given tree
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->right->left = new Node(40);
    root->right->right = new Node(60);
    root->right->left->left = new Node(50);
    root->right->right->right = new Node(70);

    // fn call
    cout << diameter(root) << "\n";
    cout << diameterOptimized(root);
}