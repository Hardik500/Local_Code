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

    //My solution
    Node *reverseList(Node *head, int k)
    {
        Node *prev = NULL, *curr = head, *temp = NULL;

        int counter = k;

        while (curr != NULL && counter--)
        {
            prev = createNewNode(curr->data); //Get the current node
            prev->next = temp;                //Store the value of previous in this node

            temp = prev;       //Change the previous node
            curr = curr->next; //Move to next item
        }

        Node *extra = temp;

        while (extra->next)
            extra = extra->next;

        extra->next = curr;

        if (curr)
            extra->next = reverseList(curr, k);

        return prev;
    }

    //Net solution
    struct Node *reverse(struct Node *head, int k)
    {
        Node *prev = NULL;
        Node *curr = head;
        Node *q;
        int counter = k;
        while (counter-- && curr != NULL)
        {
            q = curr->next;
            curr->next = prev;
            prev = curr;
            curr = q;
        }
        if (head != NULL)
            head->next = reverse(q, k);
        return prev;
    }

    void printLL(Node *head, int count = 0)
    {
        cout << head->data << "\n";

        if (head->next != NULL)
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
    ll.insert(root, 6);

    root2 = ll.reverseList(root, 2);

    ll.printLL(root2);
}