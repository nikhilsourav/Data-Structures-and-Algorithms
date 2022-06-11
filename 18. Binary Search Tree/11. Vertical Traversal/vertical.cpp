/*
    Given a binary tree, we need to print nodes in all
    vertical lines starting from leftmost line to rightmost
    ensuring that if a node is above another node in a vertical
    line then that (above) node should be printed first


        40
       /  \
      20   60
     / \   / \
    10 30 50 70

    output: 10 20 40 30 50 60 70
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

/*
    Here we must use level order traveral to ensure that
    topmost node is printed first
*/
void verticalTraversal(Node *root)
{
    // init queue of pair (Node, int)
    queue<pair<Node *, int>> container;
    container.push({root, 0});

    // init map
    map<int, vector<int>> mp;

    // logic:
    while (!container.empty())
    {
        // get hold of queue content
        auto quContent = container.front();

        // destructure node and offset
        Node *curr = quContent.first;
        int offset = quContent.second;

        // push in map
        mp[offset].push_back(curr->key);

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
    {
        for (int val : pair.second)
            cout << val << " ";
        cout << endl;
    }
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
    verticalTraversal(root);
}