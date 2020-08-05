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
    void removeLoop(Node *head)
    {
        if (!head)
            return;

        Node *fast = head->next;
        Node *slow = head;

        while (fast != slow)
        {
            if (!fast || !fast->next)
                return;
            fast = fast->next->next;
            slow = slow->next;
        }

        int size = 1;
        fast = fast->next;
        while (fast != slow)
        {
            size++;
            fast = fast->next;
        }

        slow = head;
        fast = head;
        for (int i = 0; i < size - 1; i++)
            fast = fast->next;

        while (fast->next != slow)
        {
            fast = fast->next;
            slow = slow->next;
        }
        fast->next = NULL;
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

    root->next->next->next->next->next = root->next->next;

    ll.removeLoop(root);

    ll.printLL(root);
}