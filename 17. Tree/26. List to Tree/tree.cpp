/*
    Given a Linked List Representation of Complete Binary Tree.
    The task is to construct the Binary tree.

    input list = 1->2->3->4->5

    Output: 1 2 3 4 5

        The tree would look like this
                  1
                /   \
               2     3
             /  \
            4   5

*/
#include <bits/stdc++.h>
using namespace std;

// Linked List Node
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// Tree Node
struct TreeNode
{
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Convert linked list to complete binary tree
void convert(Node *head, TreeNode *&root)
{
    // init vars
    queue<TreeNode *> qu;
    root = new TreeNode(head->data);
    qu.push(root);

    // logic:
    while (!qu.empty())
    {
        // take out a tree node
        TreeNode *curr = qu.front();
        qu.pop();

        // left child
        if (head->next)
        {
            curr->left = new TreeNode(head->next->data);
            qu.push(curr->left);
            head = head->next;
        }

        // right child
        if (head->next)
        {
            curr->right = new TreeNode(head->next->data);
            qu.push(curr->right);
            head = head->next;
        }
    }
}

// LevelOrder traversal of tree
void levelOrder(TreeNode *root)
{
    queue<TreeNode *> qu;
    qu.push(root);
    while (!qu.empty())
    {
        TreeNode *curr = qu.front();
        qu.pop();
        cout << curr->data << " ";
        if (curr->left)
            qu.push(curr->left);
        if (curr->right)
            qu.push(curr->right);
    }
}
// Driver code
int main()
{
    // Given list
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    // Tree root node
    TreeNode *root = NULL;
    convert(head, root);
    levelOrder(root);
}