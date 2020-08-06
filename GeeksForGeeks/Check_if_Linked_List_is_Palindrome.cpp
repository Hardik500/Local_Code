// { Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
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

bool isPalindrome(Node *head);
/* Driver program to test above function*/
int main()
{
    int T, i, n, l, firstdata;
    cin >> T;
    while (T--)
    {

        struct Node *head = NULL, *tail = NULL;
        cin >> n;
        // taking first data of LL
        cin >> firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for (i = 1; i < n; i++)
        {
            cin >> l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        cout << isPalindrome(head) << endl;
    }
    return 0;
}

// } Driver Code Ends

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node *reverse(Node *head)
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

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    fast = head;
    slow = reverse(slow);

    while (fast != NULL && fast->next != NULL)
    {
        if(fast->data != slow->data){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }

    return true;
}