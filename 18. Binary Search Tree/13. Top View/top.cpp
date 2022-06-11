/*
    Given a binary tree print its top view.

        40
       /  \
      20   60
     / \   / \
    10 30 50 70

    output: 10 20 40 60 70
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

// Print top view
void topView(Node *root)
{
    // init queue of pair (Node, int)
    queue<pair<Node *, int>> container;
    container.push({root, 0});

    // init map
    map<int, int> mp;

    // logic:
    while (!container.empty())
    {
        // get hold of queue content
        auto quContent = container.front();

        // destructure node and offset
        Node *curr = quContent.first;
        int offset = quContent.second;

        // push an offset only if there is no value for current offset
        if (mp.find(offset) == mp.end())
            mp[offset] = (curr->key);

        // delete from queue
        container.pop();

        // push children if possible
        if (curr->left)
            container.push({curr->left, offset - 1});
        if (curr->right)
            container.push({curr->right, offset + 1});
    }

    // output
    for (auto pair : mp)
        cout << pair.second << " ";
}

// Driver code
int main()
{
    /*

            10
           /  \
          20   30
         / \
        40 50

    */
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);

    // fn call
    topView(root);
}