#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left = NULL;
    Node *right = NULL;
};

Node *getNewNode(int data)
{
    Node *temp = new Node();
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void printBFS(Node *root)
{

    if (root == NULL)
        return;

    queue<Node *> q;

    q.push(root);

    while (q.empty() == false)
    {
        Node *node = q.front();
        cout<<node->data<<" ";
        q.pop();

        if(node->left != NULL){
            q.push(node->left);
        }

        if(node->right != NULL){
            q.push(node->right);
        }
    }
}

int main()
{
    Node *root = getNewNode(1);
    root->left = getNewNode(2);
    root->right = getNewNode(3);
    root->left->left = getNewNode(4);
    root->left->right = getNewNode(5);
    root->right->left = getNewNode(6);
    root->right->right = getNewNode(7);

    printBFS(root);

    return 0;
}