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

Node *createNode(int data)
{
    Node *root = new Node(data);
    root->left = NULL;
    root->right = NULL;

    return root;
}

string serialize(Node *root)
{
    if (root == NULL)
        return "#";
    return to_string(root->data) + "," + serialize(root->left) + "," + serialize(root->right);
}

Node *makeDeserialize(stringstream &s)
{
    string str;
    getline(s, str, ',');
    if (str == "#" || !str.size())
        return NULL;
    else
    {
        Node *root = createNode(stoi(str));
        root->left = makeDeserialize(s);
        root->right = makeDeserialize(s);
        return root;
    }
}

Node *deserialize(string data)
{
    if (data == "#")
        return NULL;
    stringstream s(data);
    return makeDeserialize(s);
}

int main()
{
    string bstTree = "1,2,3,#,#,4,5";

    Node *root = deserialize(bstTree);

    string bstSerialized = serialize(root);

    cout << bstSerialized << "\n";
}