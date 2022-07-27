#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = NULL;
    }
};

// print
void preOrder(Node *node)
{
    if (node == NULL)
        return;
    printf("%d ", node->data);
    preOrder(node->left);
    preOrder(node->right);
}

// function to return the index of complementary close parenthesis
int findIndex(string str, int startIdx, int endIndex)
{
    if (startIdx > endIndex)
        return -1;

    // Inbuilt stack
    stack<char> s;

    for (int i = startIdx; i <= endIndex; i++)
    {

        // if open parenthesis tartIdxs, push it
        if (str[i] == '(')
            s.push(str[i]);

        // if close parenthestartIdxs
        else if (str[i] == ')')
        {
            if (s.top() == '(')
            {
                s.pop();

                // if stack becoms empty, return index
                if (s.empty())
                    return i;
            }
        }
    }

    // if not found return -1
    return -1;
}

// function to construct tree from string
Node *treeFromString(string str, int startIdx, int endIndex)
{
    // Base case
    if (startIdx > endIndex)
        return NULL;

    // new root
    Node *root = new Node(str[startIdx] - '0');

    // if next char is '(' find the index of its complement ')'
    int index = -1;
    if (startIdx + 1 <= endIndex && str[startIdx + 1] == '(')
        index = findIndex(str, startIdx + 1, endIndex);

    // if index found
    if (index != -1)
    {
        // call for left subtree
        root->left = treeFromString(str, startIdx + 2, index - 1);

        // call for right subtree
        root->right = treeFromString(str, index + 2, endIndex - 1);
    }

    // return newly created root
    return root;
}

// Driver Code
int main()
{
    // Given string
    string str = "4(2(3)(1))(6(5))";
    int startIdx = 0;
    int endIndex = str.size() - 1;

    // fn call
    Node *root = treeFromString(str, startIdx, endIndex);
    preOrder(root);
}
