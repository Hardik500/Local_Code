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

void printZigZag(Node *root)
{
    // if null then return
    if (!root)
        return;

    // declare two stacks
    stack<struct Node *> currentlevel;
    stack<struct Node *> nextlevel;

    // push the root
    currentlevel.push(root);

    // check if stack is empty
    bool lefttoright = true;

    while (!currentlevel.empty())
    {

        // pop out of stack
        struct Node *temp = currentlevel.top();
        currentlevel.pop();

        // if not null
        if (temp)
        {
            // print the data in it
            cout << temp->data << " ";

            // store data according to current
            // order.
            if (lefttoright)
            {
                if (temp->left)
                    nextlevel.push(temp->left);
                if (temp->right)
                    nextlevel.push(temp->right);
            }
            else
            {
                if (temp->right)
                    nextlevel.push(temp->right);
                if (temp->left)
                    nextlevel.push(temp->left);
            }
        }

        if (currentlevel.empty())
        {
            lefttoright = !lefttoright;
            swap(currentlevel, nextlevel);
        }
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

    printZigZag(root);
}