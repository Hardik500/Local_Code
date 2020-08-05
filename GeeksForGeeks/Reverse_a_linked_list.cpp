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

    Node *reverseList_rec(Node *head)
    {

        if (head->next == NULL)
            return head;

        Node *newHead = reverseList_rec(head->next);
        head->next->next = head;
        head->next = NULL;

        return newHead;
    }

    //Net solution
    Node *reverseList_ite_net(Node *head)
    {
        if (head->next == NULL)
            return head;

        Node *prev = NULL, *curr = head, *next = NULL;

        while (curr != NULL)
        {
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

    //My solution
    Node *reverseList_ite(Node *head)
    {
        if (head->next == NULL)
            return head;

        Node *prev = NULL, *curr = head, *temp;

        int count = 0;

        while (curr != NULL)
        {
            prev = createNewNode(curr->data); //Get the current node
            prev->next = temp; //Store the value of previous in this node

            temp = prev; //Change the previous node
            curr = curr->next; //Move to next item
        }

        return prev;
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

    root2 = ll.reverseList_ite_net(root);

    ll.printLL(root2);
}