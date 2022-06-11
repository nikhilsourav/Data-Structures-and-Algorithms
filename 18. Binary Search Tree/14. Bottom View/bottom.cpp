/*
    Given a binary tree print its bottom view.
    In case of a tie print rightmost node

        40
       /  \
      20   60
     / \   / \
    10 30 50 70

    output: 10 20 50 60 70
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
    When we se a node for a particular horizontal distance
    if there is no node for that horizontal distance we insert
    it, if there is a node then we override it

    Since we're doing level order traversal and we're always
    overriding node value, ultimately we end up with the node
    which is required bottom view node
*/
void bottomView(Node *root)
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

        /*
            if (mp.find(offset) == mp.end())
            only change from top view
            override current offset's value
        */
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
    for (auto x : mp)
        cout << x.second << " ";
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
    bottomView(root);
}