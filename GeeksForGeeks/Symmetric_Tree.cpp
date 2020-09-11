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

// vector<int> leftV, rightV;

// void pushOnVectorLeft(Node *root)
// {
//     leftV.push_back(root->data);

//     if (root->left)
//         pushOnVectorLeft(root->left);
//     else
//         leftV.push_back(-1);

//     if (root->right)
//         pushOnVectorLeft(root->right);
//     else
//         leftV.push_back(-1);
// }

// void pushOnVectorRight(Node *root)
// {
//     rightV.push_back(root->data);

//     if (root->right)
//         pushOnVectorRight(root->right);
//     else
//         rightV.push_back(-1);

//     if (root->left)
//         pushOnVectorRight(root->left);
//     else
//         rightV.push_back(-1);
// }

// bool isSymmetric(Node *root)
// {
//     if (root == NULL)
//         return false;

//     leftV.push_back(root->data);
//     rightV.push_back(root->data);

//     pushOnVectorLeft(root->left);
//     pushOnVectorRight(root->right);

//     return false;
// }

bool helper(Node *l, Node *r)
{
    if (l == r)
        return true;
    else if (!l || !r || l->data != r->data)
        return false;
    return helper(l->left, r->right) && helper(l->right, r->left);
}

bool isSymmetric(Node *root)
{
    if (!root)
        return true;
    return helper(root->left, root->right);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(2);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->left = new Node(4);
    root->right->right = new Node(3);

    bool x = isSymmetric(root);
}