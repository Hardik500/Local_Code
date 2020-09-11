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

Node *buildTree_rec(vector<int> &inorder, int i1, int i2, vector<int> &preorder, int p1, int p2, unordered_map<int, int> mp)
{
    if (i1 >= i2 || p1 >= p2)
        return NULL;

    Node *root = new Node(preorder[p1]);
    int index = mp[root->data];
    int diffIndex = index - i1;

    root->left = buildTree_rec(inorder, i1, i1 + diffIndex, preorder, p1 + 1, p1 + diffIndex + 1, mp);
    root->right = buildTree_rec(inorder, i1 + diffIndex, i2, preorder, p1 + diffIndex + 1, p2, mp);

    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &preorder)
{
    int n = inorder.size();

    unordered_map<int, int> mp;

    if (!n)
        return NULL;

    for (int i = 0; i < n; i++)
        mp[inorder[i]] = i;

    return buildTree_rec(inorder, 0, n, preorder, 0, n, mp);
}

int main()
{
    vector<int> inorder = {4, 2, 5, 1, 6, 3};
    vector<int> preorder = {1, 2, 4, 5, 3, 6};

    Node *root = buildTree(inorder, preorder);

    cout<<"hello"<<"\n";
}