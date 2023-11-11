#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// Binary Search Tree 

// 1) Creation 
class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};


// 2) Inserting 
void insertNode(Node* &root,int d){
    // base case 
    if(root == NULL){
        root = new Node(d);
        return ;
    }

    if(d>root->data)
        insertNode(root->right,d);
    else
        insertNode(root->left,d);
}

void takeInput(Node* &root){
    int data;
    cin >> data;
    while (data!=-1)
    {
        insertNode(root,data);
        cin >> data; 
    }
}


// 3) Searching 
bool searching(Node* root,int k){
    while(root!=NULL)
    {
        if(root->data>k)
            root = root->right;
        else if(root->data<k)
            root = root->left;
        else
            return true;
    }
    return false;
}



// 4) Minimun value 
Node* minVal(Node* root){
    if(root->left == NULL)
        return root;
    minVal(root->left);
}



// 5) Deleting 
Node* deleting(Node* root,int val){
    if(root==NULL)
        return root;
    
    if(root->data==val){
        // 0 child 
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child

        // left child 
        else if(root->left != NULL && root->right==NULL){
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // right child 
        else if(root->right != NULL && root->left==NULL){
            Node* temp = root->right;
            delete root;
            return temp;
        }

        // 2 child
        else if(root->right != NULL && root->left!=NULL){
            int mini = minVal(root->right) -> data;
            root->data = mini;
            root->right = deleting(root->right,mini);
            return root;
        }
    }
    else if(root->data > val){
        root->left = deleting(root->left,val);
        return root;
    }
    else{
        root->right = deleting(root->right,val);
        return root;
    }
}


int main(){
    
    return 0;
}