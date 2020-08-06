// { Driver Code Starts
// driver

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>
using namespace std;

/* Linked list Node */
struct Node
{
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

struct Node *buildList(int size)
{
    int val;
    cin >> val;

    Node *head = new Node(val);
    Node *tail = head;

    for (int i = 0; i < size - 1; i++)
    {
        cin >> val;
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node *n)
{
    while (n)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

struct Node *addTwoLists(struct Node *first, struct Node *second);

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;

        cin >> n;
        Node *first = buildList(n);

        cin >> m;
        Node *second = buildList(m);

        Node *res = addTwoLists(first, second);
        printList(res);
    }
    return 0;
}
// } Driver Code Ends

/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

//Note: Unexpected answers
// Node *revereList(Node *head)
// {
//     if (head->next == NULL)
//     {
//         return head;
//     }

//     Node *reversedList = revereList(head->next);
//     head->next->next = head;
//     head->next = NULL;

//     return reversedList;
// }

// Node *returnSum(Node *first, Node *second, int carry = 0, int total = 0)
// {
//     if (first == NULL && second == NULL)
//     {
//         Node *temp = new Node(total);
//         temp->next = NULL;

//         if(total)
//             return temp;
//         else
//             return NULL;
//     }
//     else if (first == NULL)
//     {
//         second->data += carry;
//         return second;
//     }
//     else if (second == NULL)
//     {
//         first->data += carry;
//         return first;
//     }
//     else
//     {
//         int sum = (first->data + second->data + carry );
//         if (sum >= 10)
//         {
//             first->data = sum % 10;
//             int total = sum / 10;
//             first->next = returnSum(first->next, second->next, 1, total);
//         }
//         else
//         {
//             first->data = sum;
//             first->next = returnSum(first->next, second->next, 0);
//         }
//     }
//     return first;
// }

// struct Node *addTwoLists(struct Node *first, struct Node *second)
// {
//     Node *temp1 = revereList(first);
//     Node *temp2 = revereList(second);

//     Node *temp = returnSum(temp1, temp2);

//     Node *temp4 = revereList(temp);

//     return temp4;
// }

//Right Solution
// Node *reverse(Node *head)
// {
//     Node *curr = head;
//     Node *next = NULL;
//     Node *prev = NULL;

//     while (curr)
//     {
//         next = curr->next;
//         curr->next = prev;
//         prev = curr;
//         curr = next;
//     }
//     head = prev;
//     return head;
// }
// void addBack(Node *&head, Node *&last, int data)
// {

//     Node *newNode = new Node(data);
//     //   newNode->data=data;
//     newNode->next = NULL;

//     if (last == NULL)
//     {
//         head = newNode;
//     }
//     else
//     {
//         last->next = newNode;
//     }
//     last = newNode;
// }
// Node *addTwoLists(Node *first, Node *second)
// {

//     Node *head1 = reverse(first);
//     Node *head2 = reverse(second);
//     Node *res;
//     Node *last = NULL; // Last node of new list
//     int total, carry = 0;
//     // One of them not NULL
//     while (head1 || head2)
//     {

//         int a = (head1) ? (head1->data) : (0); // If NULL contri is 0
//         int b = (head2) ? (head2->data) : (0);

//         total = (a + b + carry);
//         carry = (total / 10);
//         total = total % 10;

//         // Add this to back of new list
//         addBack(res, last, total);

//         if (head1)
//         {
//             head1 = head1->next;
//         }

//         if (head2)
//         {
//             head2 = head2->next;
//         }
//     }
//     if (carry != 0)
//     {
//         addBack(res, last, carry);
//     }
//     res = reverse(res);
//     return res;
// }

//Note: More simpler solution
Node *reverse(Node *head)
// this function reverses the linked list
{
    Node *prev = NULL;
    Node *current = head;
    Node *next;

    while (current != NULL)
    {
        next = current->next; // storing next node
        current->next = prev; // linking current node to previous
        prev = current;       // updating prev
        current = next;       // updating current
    }

    return prev;
}

struct Node *addTwoLists(struct Node *first, struct Node *second)
{
    first = reverse(first);   // reversing lists
    second = reverse(second); // to simplify addition

    Node *sum = NULL;
    int carry = 0;

    while (first != NULL || second != NULL || carry != 0)
    {
        int newVal = carry;
        if (first)
            newVal += first->data;
        if (second)
            newVal += second->data;
        // newly value for sumList is sum of carry and respective
        // digits in the 2 lists

        carry = newVal / 10;  // updating carry
        newVal = newVal % 10; // making sure newVal is <10

        Node *newNode = new Node(newVal);
        newNode->next = sum; // appending newVal node
        sum = newNode;

        if (first)
            first = first->next; // moving to next node
        if (second)
            second = second->next;
    }

    return sum;
}