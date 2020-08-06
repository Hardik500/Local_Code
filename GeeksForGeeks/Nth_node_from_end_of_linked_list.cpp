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

    int get_nth_node(Node *head, int k)
    {
        int size = 1;

        Node *temp = head;

        while (temp->next)
        {
            temp = temp->next;
            size++;
        }

        int last_size = size - k;

        while (last_size--)
            head = head->next;

        return head->data;
    }

    void printLL(Node *head, int count = 0)
    {
        cout << head->data << "\n";

        if (count == 4)
        {
            return;
        }

        if (head->next)
            printLL(head->next, count + 1);
    }
};

int main()
{
    Node *root, *root2;
    root = NULL;

    LinkedList ll;

    ll.insert(root, 1);
    ll.insert(root, 2);
    ll.insert(root, 3);
    ll.insert(root, 4);
    ll.insert(root, 5);

    cout<<ll.get_nth_node(root, 2);

}