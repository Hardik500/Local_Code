#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
    Node *prev;
};

class LinkedList
{
public:
    Node *createNewNode(int data)
    {
        Node *newNode = new Node();
        newNode->data = data;
        newNode->next = NULL;
        return newNode;
    }

    void insertNewNode(Node *&newroot, Node *&root, int data)
    {
        if (root == NULL)
        {
            root = createNewNode(data);

            if (newroot)
                root->prev = newroot;
        }
        else
            insertNewNode(root, root->next, data);
    }

    void printLinkedList(Node *root)
    {
        cout << root->data << " " << root->prev->data << "\n";
        
        if (root->next != NULL)
            printLinkedList(root->next);
    }
};

int main()
{
    Node *root;
    root = NULL;
    LinkedList l;
    l.insertNewNode(root, root, 4);
    l.insertNewNode(root, root, 2);
    l.insertNewNode(root, root, 7);
    l.insertNewNode(root, root, 1);
    l.insertNewNode(root, root, 3);
    l.insertNewNode(root, root, 6);
    l.insertNewNode(root, root, 9);

    l.printLinkedList(root);
}