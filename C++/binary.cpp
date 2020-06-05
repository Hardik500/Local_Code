#include <bits/stdc++.h> 
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class Binary {
    public:
        Node* getNewNode(int data){
            Node* newNode = new Node();
            // (*newNode).data = data; 
            //OR
            newNode->data = data;
            newNode->left = NULL;
            newNode->right = NULL;
            return newNode;
        }

        void insert(Node* &root, int data){
            if(root == NULL){
                root = getNewNode(data);
            }
            else if(data > root->data){
                insert(root->right, data);
            }
            else {
                insert(root->left, data);
            }
        }

        void remove(Node* &root, int data){
            if(root == NULL){
                return;
            }
            else if(root->data == data){
                if(root->right == NULL){
                    root = root->left;
                }
                else if(root->left == NULL){
                    root = NULL;
                }
                else{
                    root = root->right;
                }
            }
            else{
                if(data > root->data)
                {
                    remove(root->right, data);
                }
                else{
                    remove(root->left, data);
                }
            }
        }

        bool search(Node* root, int data){
            if(root == NULL) return false;
            if(root->data == data) return true;
            if(root->data > data) return search(root->left, data);
            else return search(root->right, data);
        }

        void makeArray(Node* root, vector<int> &arr ){
            if(root == NULL) return;
            if(arr.empty()){
                arr.push_back(root->data);
                arr.push_back(root->left->data);
                arr.push_back(root->right->data);
            }
            else{
                if(root->left != NULL){
                    arr.push_back(root->left->data);
                }
                if(root->right != NULL){
                    arr.push_back(root->right->data);
                }
            }
            makeArray(root->left, arr);
            makeArray(root->right, arr);
        }

        void inverse(Node* &root){
            if(root == NULL) return;
            else{
                if(root->left == NULL and root->right == NULL){
                    return;
                }
                else if(root->left == NULL){
                    root->left = root->right;
                    root->right = NULL;
                }
                else if(root->right == NULL){
                    root->right = root->left;
                    root->left = NULL;
                }
                else{
                    Node* temp = root->left;
                    root->left = root->right;
                    root->right = temp;
                }
            }
            inverse(root->left);
            inverse(root->right);
        }
};

int main(){
    Node* root; //Pointer to root node
    root = NULL; //Setting tree as empty
    Binary b;
    b.insert(root, 4);
    b.insert(root, 2);
    b.insert(root, 7);
    b.insert(root, 1);
    b.insert(root, 3);
    b.insert(root, 6);
    b.insert(root, 9);
    // cout<<b.search(root, 8)<<"\n";
    // b.remove(root, 8);
    // cout<<b.search(root, 8)<<"\n";
    vector<int> bstToArr = {};
    b.makeArray(root, bstToArr);
    
    for(auto x:bstToArr){
        cout<<x<<" ";
    }

    cout<<"\n";

    //Inverse bst

    // b.inverse(root);
    // vector<int> bstToArrInv = {};
    // b.makeArray(root, bstToArrInv);
    // for(auto x:bstToArrInv){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";

}