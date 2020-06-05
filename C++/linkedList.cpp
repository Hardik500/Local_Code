#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    public:
        Node* createNewNode(int data){
            Node* newNode = new Node();
            newNode->data = data;
            newNode->next = NULL;
            return newNode;
        }

        void insert(Node* &root, int data){
            if(root == NULL){
                root = createNewNode(data);
            }
            else {
                insert(root->next, data);
            }
        }
        
        bool search(Node* root, int data){
            if(root->data == data) return true;
            else if(root->next != NULL){
                return search(root->next, data);
            }
            else return false;
        }

        void remove(Node* &root, int data){
            if(root == NULL){
                return;
            }
            else if(root->data == data) {
                root = root->next;
            }
            else{
                remove(root->next, data);
            }
        }
        
        void makeArray(Node* root, vector<int> &arr){
            if(root == NULL) return;
            arr.push_back(root->data);
            makeArray(root->next, arr);
        }
};

int main() {
    Node* root;
    root = NULL;
    LinkedList l;
    l.insert(root, 4);
    l.insert(root, 2);
    l.insert(root, 7);
    l.insert(root, 1);
    l.insert(root, 3);
    l.insert(root, 6);
    l.insert(root, 9);

    // cout<<l.search(root, 1);

    vector<int> llToArr = {};
    l.makeArray(root, llToArr);

    for(auto x:llToArr){
        cout<<x<<" ";
    }

    // cout<<"\n";
    
    // l.remove(root, 1);

    // vector<int> llToArrRem = {};
    // l.makeArray(root, llToArrRem);

    // for(auto x:llToArrRem){
    //     cout<<x<<" ";
    // }

}