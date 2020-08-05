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

    //With STL
    int intersectPoint_stl(Node *head1, Node *head2)
    {
        unordered_set<Node *> s;

        while (head1)
        {
            s.insert(head1);
            head1 = head1->next;
        }

        while (head2)
        {
            if (s.find(head2) != s.end())
            {
                return head2->data;
            }
            head2 = head2->next;
        }

        return -1;
    }

    //WIthout STL
    int intersectPoint(Node *head1, Node *head2)
    {
        int n1 = 0, n2 = 0;
        Node *temp;

        for (temp = head1; temp; temp = temp->next)
            n1++;
        // finding length of list 1

        for (temp = head2; temp; temp = temp->next)
            n2++;
        // finding length of list 2

        for (; n1 > n2; n1--)
            head1 = head1->next;
        // if list1 is longer, we ignore some of its starting
        // elements till it has as many elements as list2

        for (; n2 > n1; n2--)
            head2 = head2->next;
        // similarly
        // if list2 is longer, we ignore some of its starting
        // elements till it has as many elements as list1

        while (head1 != head2)
        {
            head1 = head1->next;
            head2 = head2->next;
            // now we simple traverse ahead till we get the
            // intersection point, if there is none, this loop
            // will break when both pointers point at NULL
        }

        if (head1)
            return head1->data;
        // if head1 is not NULL, we return its data
        return -1; // otherwise we return -1
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
    root = root2 = NULL;

    LinkedList ll, ll2;

    ll.insert(root, 10);
    ll.insert(root, 20);
    ll.insert(root, 5);
    ll.insert(root, 10);

    ll2.insert(root2, 30);
    ll2.insert(root2, 40);
    ll2.insert(root2, 50);
    ll2.insert(root2, 5);
    ll2.insert(root2, 10);

    cout << ll.intersectPoint(root, root2);
}