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

    Node *rotate_list(Node *head, int k)
    {
        Node *temp = head;

        while (temp->next)
            temp = temp->next;

        temp->next = head; // linking last node with first node
        Node *end;
        while (k--)
        {
            end = head;
            head = head->next;
        }
        // end is previous of updated head, so make end of next as null as it is the last node of updated linked list
        end->next = NULL;
        return head;
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
    Node *root;
    root = NULL;

    LinkedList ll;

    ll.insert(root, 1);
    ll.insert(root, 2);
    ll.insert(root, 3);
    ll.insert(root, 4);
    ll.insert(root, 5);

    ll.printLL(ll.rotate_list(root, 3));
}