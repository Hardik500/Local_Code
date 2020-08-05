#include <bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node *next;
};

class LinkedList
{
public:
    Node *createNewNode(int data)
    {
        Node *newnode = new Node();
        newnode->data = data;
        newnode->next = NULL;
        return newnode;
    }

    void insert(Node *&root, int data)
    {
        if (root == NULL)
            root = createNewNode(data);
        else
            insert(root->next, data);
    }

    //Recursion method
    void findMiddle(Node *first, Node *second)
    {
        if (second->next == NULL)
            cout << first->data << "\n";
        else if (second->next->next != NULL)
            findMiddle(first->next, second->next->next);
        else
            cout << first->next->data;
    }

    //Iterative method
    int findMiddle(Node *head)
    {
        if (head == NULL)
            return -1;

        Node *first = head;
        Node *second = head;

        while (second && second->next)
        {
            first = first->next;
            second = second->next->next;
        }

        return first->data;
    }
};

int main()
{
    Node *root;
    root = NULL;

    LinkedList ll;

    ll.insert(root, 1);
    ll.insert(root, 2);

    // ll.findMiddle(root, root);

    cout << ll.findMiddle(root);
}