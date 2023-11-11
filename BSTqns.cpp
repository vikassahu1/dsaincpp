#include <bits/stdc++.h>
using namespace std;
// Note: Inorder of a BST is sorted. 

// Q1: To chech given tree is Bst or not 
// bool isBst(BinaryTreeNode<int>* root,int min,int max){
//     if(root == NULL)
//         return true;
    
//     if(root->data>=min && root->data<max){

        // left m jab jaega to right par ek upper limit lag jaegi and vice-versa 
//         bool left = isBst(root->left,min,root->data);
//         bool right = isBst(root->right,root->data,max);
//         return left && right;
//     }
//     else
//         return false;
// }

// bool validateBST(BinaryTreeNode<int> *root) {
//     return isBst(root,INT_MIN,INT_MAX);
// }




// Q2: To get a precessor and successor of a number in BST 
// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {
//     TreeNode *temp = root;
//     int pre = -1;
//     int suc = -1;
//     while(temp){
//         if(temp->data == key)
//             break;

//         else if(temp->data >= key){
//             suc = temp->data;
//             temp = temp->left;}

//         else{
//             pre = temp ->data;
//             root = temp ->right;}
//     }

//         TreeNode* l = temp ->left;
//         while(l){
//             pre = l->data;
//             l = l->right;
//         }

//         TreeNode* r = temp ->right;
//         while(r){
//             suc = r->data;
//             r = r->left;
//         }
//     return make_pair(pre,suc);
// }



// Q3: To get a lowest common ancestor in a BST 
// TreeNode *LCAinaBST(TreeNode *root, TreeNode *P, TreeNode *Q)
// {
//     if(root==NULL)
//         return NULL;
    
//     while(root){
//         if(root->data > P->data && root->data > Q->data)
//             root = root->left;
        
//         else if(root->data < P->data && root->data < Q->data)
//             root = root->right;
//         else
//             return root;
//     } 
//     return root;
// }



//Q4: To convert normal BST to balanced BST 
// void inorder(TreeNode<int>* root,vector<int> &ans){
//     if(root==NULL)
//         return ;

//     inorder(root->left,ans);
//     ans.push_back(root->data);
//     inorder(root->right,ans);
// }


// void solve(TreeNode<int>* &nod,vector<int> ans,int s,int e){
//     if(s>e)
//         return;
//     int m = s+(e-s)/2;

// Mid wale element ka node bana kar ke left and right ke le recursion kar lenge  
//     nod = new TreeNode<int>(ans[m]);
//     solve(nod->left,ans,s,m-1);
//     solve(nod->right,ans,m+1,e);
// }


// TreeNode<int>* balancedBst(TreeNode<int>* root) {
//     vector<int> ans;
//     inorder(root,ans);

//     TreeNode<int> * nod = NULL;
//     solve(nod,ans,0,ans.size()-1);

//     return nod;
// }



// Q3: Flattening a BST. 
// void solve(TreeNode<int>* root,vector<int> &temp){
//     if(root == NULL)
//         return;

//     solve(root->left,temp);
//     temp.push_back(root->data);
//     solve(root->right,temp);
// }

// TreeNode<int>* flatten(TreeNode<int>* root)
// {
//     vector<int> temp;    
//     solve(root,temp);
//     TreeNode<int>* ans = new TreeNode<int>(temp[0]);
//     TreeNode<int>* init = ans;
//     for(int i = 1;i<temp.size();i++){
//         TreeNode<int>* temp2 = new TreeNode<int>(temp[i]);
//         ans->right = temp2;
//         ans->left = NULL;
//         ans = temp2;
//     }
//     ans->left = NULL;
//     ans->right = NULL;
//     return init;
// }



// Q4: To check whether any two node present in the tree whose sum is equal to the given key 
// void inorder(BinaryTreeNode<int>* root,vector<int> &ans){
//     if(root==NULL)
//         return ;
    
//     inorder(root->left,ans);
//     ans.push_back(root->data);
//     inorder(root->right,ans);
// }


// bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
//     vector<int> ans;
//     inorder(root,ans);
//     int i = 0,j = ans.size()-1;
//     while(i<j){
//         int a = ans[i]+ans[j];
//         if(a==target)
//             return true;
//         else if(a<target)
//             i++;
//         else
//             j--;
//     }
//     return false;
// }




int main(){
    
    return 0;
}