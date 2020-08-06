// { Driver Code Starts
#include <bits/stdc++.h>

struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node *flatten(Node *root);

int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct Node *temp = NULL;
        struct Node *head = NULL;
        struct Node *pre = NULL;
        struct Node *tempB = NULL;
        struct Node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new Node(data);
            temp->next = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->next = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                scanf("%d", &temp_data);
                tempB = new Node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        Node *fun = head;
        Node *fun2 = head;

        Node *root = flatten(head);
        printList(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends

/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

//NOTE: TLE
// Node *insertIntoLL(Node *root, Node *val)
// {
//     Node *prev = root;
//     Node *temp = root;

//     while (temp && temp->data <= val->data)
//     {
//         if (temp->data == val->data)
//         {
//             return root;
//         }

//         prev = temp;
//         temp = temp->next;
//     }

//     prev->next = val;

//     if (prev->next)
//     {
//         prev->next->next = temp;
//     }

//     return root;
// }

// /*  Function which returns the  root of
//     the flattened linked list. */
// Node *flatten(Node *root)
// {
//     Node *temp = root;

//     while (root)
//     {
//         Node *head = root;

//         while (head)
//         {
//             temp = insertIntoLL(temp, head);
//             head = head->bottom;
//         }

//         root = root->next;
//     }

//     return temp;
// }

//Note: Right but with O(n) space complexity
// bool pro(Node* x, Node* y){
//     return x->data < y->data;
// }

// Node *flatten(Node *root)
// {
//     vector<Node*> s;

//     Node* temp = root;

//     Node* temp2 = temp;

//     while (root)
//     {
//         Node *head = root;

//         while (head)
//         {
//             s.push_back(head);
//             head = head->bottom;
//         }

//         root = root->next;
//     }

//     sort(s.begin(), s.end(), pro);

//     temp = s.front();

//     for(auto x:s){
//         temp2->bottom = x;
//         temp2 = temp2->bottom;
//     }

//     return temp;
// }

//Right answer
Node *merge(Node *h1, Node *h2)
{
    if (h1 == NULL)
        return (h2);
    if (h2 == NULL)
        return (h1);
    if (h1->data < h2->data)
    {
        h1->bottom = merge(h1->bottom, h2);
        return (h1);
    }
    else
    {
        h2->bottom = merge(h1, h2->bottom);
        return (h2);
    }
}

Node *flatten(Node *root)
{
    Node *a = root;
    Node *b = root->next;
    while (b != NULL)
    {
        Node *c = b->next;
        a = merge(a, b);
        b = c;
    }
    return (a);
}