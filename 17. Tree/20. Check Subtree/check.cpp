/*
    Check if "sub" is a subtree of "trr"

    trr            sub

      1             3
     / \           /
    2   3         4
       /
      4


    output: true

    trr                     sub

        40                  40
       /  \                /  \
      20   60             20   60
     / \   / \           / \   / \
    10 30 50 70         10 30 50 70

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

// Fn to check if sub tree Time: O(mn) Space: O(n)
bool isSubTree(Node *trr, Node *sub)
{
    // base case
    if (sub == NULL)
        return true;

    // base base
    if (trr == NULL)
        return false;

    // check the tree with root as current node
    if (checkEqual(trr, sub))
        return true;

    /*
        if tree with root as current node doesn't match
        try left and right subtree one by one
    */
    return isSubTree(trr->left, sub) || isSubTree(trr->right, sub);
}

// Driver code
int main()
{
    /*

    tre                sub

          26             10
         /  \           /  \
        10  70         20  30
       /  \           /  \
      20  30         40  60
     /  \
    40   60

    */
    Node *trr = new Node(26);
    trr->left = new Node(10);
    trr->right = new Node(70);
    trr->left->left = new Node(20);
    trr->left->right = new Node(30);
    trr->left->left->left = new Node(40);
    trr->left->left->right = new Node(40);

    Node *sub = new Node(10);
    sub->left = new Node(20);
    sub->right = new Node(30);
    sub->left->left = new Node(40);
    sub->left->right = new Node(40);

    // fn call
    cout << boolalpha << isSubTree(trr, sub);
}