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

// vector<Node *> p_path, q_path;

// bool path_found(Node *root, Node *x, vector<Node *> &x_path)
// {
//     x_path.push_back(root);

//     if (root == x)
//         return true;
//     else
//     {
//         if (root->left)
//         {
//             if (!path_found(root->left, x, x_path))
//                 x_path.pop_back();
//             else
//                 return true;
//         }
//         if (root->right)
//         {
//             if (!path_found(root->right, x, x_path))
//                 x_path.pop_back();
//             else
//                 return true;
//         }
//     }

//     return false;
// }

// Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
// {
//     path_found(root, p, p_path);
//     path_found(root, q, q_path);

//     unordered_map<Node *, int> x;

//     for (int i = 0; i < p_path.size(); i++)
//         x[p_path[i]] = 1;

//     reverse(q_path.begin(), q_path.end());

//     for (int i = 0; i < q_path.size(); i++)
//     {
//         if (x[q_path[i]])
//         {
//             return q_path[i];
//         }
//     }

//     return root;
// }

Node *lowestCommonAncestor(Node *root, Node *p, Node *q)
{
    if (!root)
        return NULL;
    if (root == p || root == q)
        return root;
    Node *l = lowestCommonAncestor(root->left, p, q);
    Node *r = lowestCommonAncestor(root->right, p, q);
    if (l && r)
        return root;
    else
        return l ? l : r;
}

int main()
{
    Node *root = new Node(3);
    root->left = new Node(5);
    root->right = new Node(1);
    root->left->left = new Node(6);
    root->left->right = new Node(2);
    root->left->right->left = new Node(7);
    root->left->right->right = new Node(4);
    root->right->left = new Node(0);
    root->right->right = new Node(8);

    cout << lowestCommonAncestor(root, root->left, root->right->right)->data;
}