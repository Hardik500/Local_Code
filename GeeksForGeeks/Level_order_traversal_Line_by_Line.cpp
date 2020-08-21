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
    queue<Node *> s, s_temp;

    s.push(root);

    cout << s.front()->data << " $ ";

    s.pop();
    s.push(root->left);
    s.push(root->right);

    while (!s.empty())
    {
        while (!s.empty())
        {
            Node *x = s.front();
            s.pop();

            cout << x->data << " ";

            if (x->left != NULL)
                s_temp.push(x->left);

            if (x->right != NULL)
                s_temp.push(x->right);
        }

        while(!s_temp.empty()){
            s.push(s_temp.front());
            s_temp.pop();
        }


        cout << "$ ";
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