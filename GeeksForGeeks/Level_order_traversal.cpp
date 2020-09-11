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

void printLevelTraversal(Node *root)
{
    queue<Node *> s;

    s.push(root);

    if(root == NULL)
        return;

    cout << s.front()->data << "\n";

    s.pop();

    if(root->left)
        s.push(root->left);
    
    if(root->right)
        s.push(root->right);

    while (!s.empty())
    {
        Node *x = s.front();
        s.pop();

        Node *y = s.front();
        s.pop();

        cout << x->data << " " << y->data << "\n";

        if (x->left != NULL)
            s.push(x->left);

        if (x->right != NULL)
            s.push(x->right);
        
        if (y->left != NULL)
            s.push(y->left);

        if (y->right != NULL)
            s.push(y->right);
    }
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(9);
    root->left->right = new Node(5);
    root->left->right->left = new Node(10);
    root->left->right->right = new Node(11);
    root->right->left = new Node(6);
    root->right->left->left = new Node(12);
    root->right->left->right = new Node(13);
    root->right->right = new Node(7);
    root->right->right->left = new Node(14);
    root->right->right->right = new Node(15);

    printLevelTraversal(root);
}