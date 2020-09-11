/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *next;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

class Solution
{
public:
    Node *connect(Node *root)
    {
        Node *leftNode = root;
        while (leftNode && leftNode->left)
        {
            populateLowerLevel(leftNode);
            leftNode = leftNode->left;
        }

        return root;
    }

    void populateLowerLevel(Node *start)
    {
        Node *iter = start;

        while (iter)
        {
            iter->left->next = iter->right;

            if (iter->next)
                iter->right->next = iter->next->left;
            iter = iter->next;
        }
    }
};