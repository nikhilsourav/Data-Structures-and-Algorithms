/*
    Given a binary search tree and a sum. Find whether there
    is a pair in the bst whose sum is equal to given sum

            10
           /   \
          8     20
         / \    / \
        4   9  11  30
                  /
                25

    sum = 33

    output: true
*/

#include <bits/stdc++.h>
using namespace std;

// Tree Node
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

// Check pair sum
bool hasPair(Node *root, int sum, unordered_set<int> &s)
{
    if (root == NULL)
        return false;

    if (hasPair(root->left, sum, s))
        return true;

    if (s.find(sum - root->key) != s.end())
        return true;
    else
        s.insert(root->key);

    return hasPair(root->right, sum, s);
}

// Driver code
int main()
{
    /*

            40
           /  \
          20   60
         / \   / \
        10 30 50 70

    */
    Node *root = new Node(40);
    root->left = new Node(20);
    root->right = new Node(60);
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right->left = new Node(50);
    root->right->right = new Node(70);

    int sum = 120;

    // fn call
    unordered_set<int> st;
    cout << boolalpha << hasPair(root, sum, st);
}