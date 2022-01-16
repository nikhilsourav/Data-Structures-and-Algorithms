### Tree

- A tree data structure is defined as a collection of objects or entities known as nodes that are linked together to represent or simulate hierarchy.

- A tree data structure is a non-linear data structure because it does not store data in a sequential manner. It is a hierarchical structure as elements in a Tree are arranged in multiple levels.

- In Tree data structure, the topmost node is known as a root node. Each node contains some data, and data can be of any type.

- Each node contains some data and the link or reference of other nodes that is called children.

**Representation:**

```
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
    root->left->left = new Node(10);
    root->left->right = new Node(30);
    root->right = new Node(60);
    root->right->left = new Node(50);
    root->right->right = new Node(70);
}
```
