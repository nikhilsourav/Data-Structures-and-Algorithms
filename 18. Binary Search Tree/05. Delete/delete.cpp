/*
    There are four possibilities while deleting a node:
    1.Node to be deleted doesn't exist. (do nothing)
    2.Node to be deleted is a leaf node. (easy)
    3.Node to be deleted has only one child. (easy)
    4.Node to be deleted has two children. (tricky)

    In case 4:

        Pick closest smaller value (inorder predecessor)
        or closest greater value (inorder successor) and
        replace the node to be deleted with any of these node

        inorder predecessor = maximum in left subtree
        inorder successor = minimum in right subtree


    case 1:

            40
           /  \
          10  60
              / \
             50 70

        delete 80

            40
           /  \
          10  60
              / \
             50 70

    case 2:

            40
           /  \
          20   60
         / \   / \
        10 30 50 70

        delete 30

            40
           /  \
          20   60
         /     / \
        10    50 70

    case 3:

            40
           /  \
          20   60
         /     / \
        10    50 70

        delete 20

            40
           /  \
          10  60
              / \
             50 70

    case 4:

            40
           /  \
          10  60
              / \
             50 70

        delete 40

    10              50
      \            /  \
      60    or    10   60
      / \               \
     50 70               70


    Time: O(h), Space O(h)
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

// Traverse
void print(Node *root)
{
    if (root != NULL)
    {
        print(root->left);
        cout << root->key << " ";
        print(root->right);
    }
}

/*
    Closest greater value (right child's leftmost leaf)

    This fn gives inorder successor only when right child is
    not null i.e. this is not a general fn to find inorder succssor
*/
Node *getSuccessor(Node *curr)
{
    // right child
    curr = curr->right;

    // find leftmost leaf
    while (curr != NULL && curr->left != NULL)
        curr = curr->left;
    return curr;
}

// Recursive delete function
Node *delNode(Node *root, int val)
{
    // base case
    if (root == NULL)
        return root;

    // if val is greater
    if (root->key > val)
        root->left = delNode(root->left, val);

    // if val is smaller
    else if (root->key < val)
        root->right = delNode(root->right, val);

    // if root->key == val
    else
    {
        // if left child doesn't exist (or it is leaf node)
        if (root->left == NULL)
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // if right child doesn't exist (or it is leaf node)
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // if left and right child exist
        else
        {
            Node *succ = getSuccessor(root);
            root->key = succ->key;
            root->right = delNode(root->right, succ->key);
        }
    }

    // return
    return root;
}

// Driver code
int main()
{
    // Given tree
    Node *root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(15);
    root->right->left = new Node(12);
    root->right->right = new Node(18);
    int x = 15;

    print(root);

    // fn call
    root = delNode(root, x);

    cout << endl;
    print(root);
}