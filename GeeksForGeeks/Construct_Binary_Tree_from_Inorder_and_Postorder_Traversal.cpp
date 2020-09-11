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

Node *buildTree_rec(vector<int> &inorder, int i1, int i2, vector<int> &postorder, int p1, int p2, unordered_map<int, int> mp)
{
    if (i1 >= i2 || p1 >= p2)
        return NULL;

    Node *root = new Node(postorder[p2 - 1]);
    int index = mp[root->data];
    int diffIndex = index - i1;

    root->left = buildTree_rec(inorder, i1, i1 + diffIndex, postorder, p1, p1 + diffIndex, mp);
    root->right = buildTree_rec(inorder, i1 + diffIndex + 1, i2, postorder, p1 + diffIndex, p2 - 1, mp);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();

    unordered_map<int, int> mp;

    if (!n)
        return NULL;

    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    return buildTree_rec(inorder, 0, n, postorder, 0, n, mp);
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    Node *root = buildTree(inorder, postorder);
}