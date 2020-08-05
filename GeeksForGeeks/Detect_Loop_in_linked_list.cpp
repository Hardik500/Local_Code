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

    //Net solution
    bool detectLoop(Node *head)
    {
        Node *first = head;
        Node *second = head;

        while (first && second && second->next)
        {
            first = first->next;
            second = second->next->next;

            if (first == second)
                return true;
        }

        return false;
    }

    void printLL(Node *head)
    {
        cout << head->data << "\n";

        if (head->next != NULL)
            printLL(head->next);
    }
};

int main()
{
    Node *root;
    root = NULL;

    LinkedList ll;

    ll.insert(root, 1);

    ll.insert(root, 2);
    ll.insert(root, 3);
    ll.insert(root, 4);
    ll.insert(root, 5);

    // root->next->next = root;

    cout << ll.detectLoop(root);
}