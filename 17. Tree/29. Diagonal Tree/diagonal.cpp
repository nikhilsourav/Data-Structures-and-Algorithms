/*
    Given a Binary Tree, diagonal the diagonal traversal
    of the binary tree.

    Input :
            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13

    Output : 8 10 14 3 6 7 13 1 4

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

// traverse
void dfs(Node *root, int cnt, map<int, vector<int>> &mp)
{
    if (root == nullptr)
        return;

    mp[cnt].push_back(root->key);
    dfs(root->left, cnt + 1, mp);
    dfs(root->right, cnt, mp);
}

vector<int> diagonal(Node *root)
{
    map<int, vector<int>> mp;
    dfs(root, 0, mp);

    vector<int> res;
    for (auto pr : mp)
        for (auto val : pr.second)
            res.push_back(val);

    return res;
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

    // fn call
    vector<int> res = diagonal(root);

    for (auto val : res)
        cout << val << " ";
}