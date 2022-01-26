/*
    Given a Binary Tree of N nodes. Find the vertical width of the tree.
    The width of a binary tree is the number of vertical paths in that tree.
          1
        /   \
       2     3
      / \   / \
     4   5  6  7
            \   \
             8  9

    output: 6
    https://bit.ly/3n4dR9S
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
    Algorithm:
        Maintain an unordered_set and a variable x = 0

        For every node if we traverse left decrement variable
        and insert in set

        If we traverse right increment variable and insert in set

        At any point, a vertical line through multiple nodes will
        have same value of x

        In the end set.size() will contain all distinct vertial lines
*/

// Helper fn for vertical width
void helper(Node *root, int x, unordered_set<int> &st)
{
    // base condition
    if (root == NULL)
        return;

    // insert variable in set
    st.insert(x);

    // traverse left and right respectively
    helper(root->left, x - 1, st);
    helper(root->right, x + 1, st);
}

// Check if two trees are equal
int verticalWidth(Node *root)
{
    // maintain an unordered_set and a variable
    unordered_set<int> st;
    int x = 0;

    // fn call
    helper(root, x, st);

    // answer
    return st.size();
}

// Driver code
int main()
{
    // Given trees
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    root->right->right->right = new Node(9);

    // fn call
    cout << verticalWidth(root);
}