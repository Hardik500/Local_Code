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

vector<int> x;

void preorderTraversal_rec(Node *root)
{
    if (root == NULL)
        return;

    x.push_back(root->data);
    preorderTraversal_rec(root->left);
    preorderTraversal_rec(root->right);
}

void preorderTraversal_iter(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;

    s.push(root);

    while (!s.empty())
    {
        Node *temp = s.top();
        s.pop();
        x.push_back(temp->data);

        if (temp->right)
            s.push(temp->right);
        if (temp->left)
            s.push(temp->left);
    }
}

void inorderTraversal_rec(Node *root)
{
    if (root == NULL)
        return;

    inorderTraversal_rec(root->left);
    x.push_back(root->data);
    inorderTraversal_rec(root->right);
}

void inorderTraversal_iter(Node *root)
{
    if (root == NULL)
        return;

    Node *curr = root;
    stack<Node *> s;

    while (curr || !s.empty())
    {
        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        curr = s.top();
        s.pop();
        x.push_back(curr->data);
        curr = curr->right;
    }
}

void postOrderTraversal_rec(Node *root)
{
    if (root == NULL)
        return;

    postOrderTraversal_rec(root->left);
    postOrderTraversal_rec(root->right);
    x.push_back(root->data);
}

void postOrderTraversal_iter(Node *root)
{
    if (root == NULL)
        return;

    stack<Node *> s;
    Node *curr = root;
    Node *last = NULL;

    while (curr || !s.empty())
    {
        if (curr)
        {
            s.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *topNode = s.top();

            if (topNode->right && last != topNode->right)
                curr = topNode->right;
            else
            {
                x.push_back(topNode->data);
                last = topNode;
                s.pop();
            }
        }
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    postOrderTraversal_iter(root);

    for (auto y : x)
        cout << y << "\n";
}