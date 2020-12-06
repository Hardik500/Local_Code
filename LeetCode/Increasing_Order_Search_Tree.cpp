#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode *increasingBST(TreeNode *root)
    {
        TreeNode* temp;
        TreeNode* newRoot = new TreeNode();
        temp = newRoot;
        inorderD(root, newRoot);
        return temp->right;
    }

    void inorderD(TreeNode *root, TreeNode*& newRoot)
    {
        if (!root) return;
        inorderD(root->left, newRoot);
        newRoot->right = new TreeNode(root->val);
        newRoot = newRoot->right;
        inorderD(root->right, newRoot);
    }

    void inorder(TreeNode *root)
    {
        if (root->left)
            inorder(root->left);
        cout << root->val;
        if (root->right)
            inorder(root->right);
    }
};

int main()
{
    TreeNode *root = new TreeNode(5);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->right = new TreeNode(7);

    Solution s;
    TreeNode *newRoot = s.increasingBST(root);

    s.inorder(newRoot);
}