#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

bool getTheSum(Node *root, int sum, int sumOfPaths = 0)
{

    if (sumOfPaths == sum && !root->left && !root->right)
        return true;

    if (root->left)
    {
        if (getTheSum(root->left, sum, sumOfPaths + root->left->data))
            return true;
    }

    if (root->right)
    {
        if (getTheSum(root->right, sum, sumOfPaths + root->right->data))
            return true;
    }

    return false;
}

bool hasPathSum(Node *root, int sum)
{
    if (!root)
        return false;

    int sumOfPaths = root->data;

    return getTheSum(root, sum, sumOfPaths);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(-2);
    root->right = new Node(-3);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    root->left->left->left = new Node(-1);
    root->right->left = new Node(-2);

    cout << hasPathSum(root, -1);
}