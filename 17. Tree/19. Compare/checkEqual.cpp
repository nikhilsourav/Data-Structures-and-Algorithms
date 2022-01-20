/*
    Given two binary trees, check if both of them are identical or not.

    eg:
           1          1
         /   \      /   \
        2     3    2     3

    output: true

           1          1
         /   \      /   \
        2     3    3     2

    output: false
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

// Check if two trees are equal
bool checkEqual(Node *r1, Node *r2)
{
    if (r1 == NULL and r2 == NULL)
        return true;
    if (r1 == NULL and r2 != NULL)
        return false;
    if (r1 != NULL and r2 == NULL)
        return false;
    if (r1->key != r2->key)
        return false;

    return checkEqual(r1->left, r2->left) and checkEqual(r1->right, r2->right);
}

// Driver code
int main()
{
    // Given trees
    Node *r1 = new Node(1);
    r1->left = new Node(2);
    r1->right = new Node(3);

    Node *r2 = new Node(1);
    r2->left = new Node(2);
    r2->right = new Node(3);

    // fn call
    cout << boolalpha << checkEqual(r1, r2);
}