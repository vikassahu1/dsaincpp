#include <iostream>
#include <queue>
using namespace std;

// To get height of a tree 
// int height(struct Node* node){
//         int cnt = 0;
//         queue<Node*> q;
//         q.push(node);
//         q.push(NULL);
//         while(!q.empty()){
//             Node* temp = q.front();
//             q.pop();
//             if(temp==NULL){
//                 cnt++;
//             if(!q.empty())
//                 q.push(NULL);
//             }
//             else{
//             if(temp->left)
//                 q.push(temp->left);
//             if(temp->right)
//                 q.push(temp->right);    
//         }
//     }
//     return cnt;
//     }

// Recursion approch 
// int height(struct Node* node){
//         if(node==NULL)
//             return 0;
        
//         int left = height(node->left);
//         int right = height(node->right);
        
//         return  max(left,right)+1;
//     }




// to calculate diameter of a tree  
    // pair<int,int> diameterFast(Node* root){
    //     // base case 
    //     if(root==NULL){
    //         pair<int,int> p = make_pair(0,0);
    //         return p;
    //     }
        
    //     // left side ka diameter calculate karta h 
    //     pair<int,int> left = diameterFast(root->left);
    //     right side ka krta h .
    //     pair<int,int> right = diameterFast(root->right);
        
    //     int op1 = left.first;
    //     int op2 = right.first;

    //     second wala height calculate karta h dono side ka .
    //     int op3 = (left.second + right.second +1);
        
    //     pair<int,int> ans;
    //     ans.first = max(op1,max(op2,op3));
    //     ans.second = max(left.second,right.second)+1;
        
    //     return ans;
        
    // }

    // Function to return the diameter of a Binary Tree.
    // int diameter(Node* root) {
    //     return diameterFast(root).first;
    // }





// Q3: to check whether a tree is balanced or not (for all node)
//     int height(struct Node* node){
//         if(node==NULL)
//             return 0;
        
//         int left = height(node->left);
//         int right = height(node->right);
        
//         return  max(left,right)+1;
//     }
// Function to check whether a binary tree is balanced or not.
//     bool isBalanced(Node *root)
//     {
//         if(root==NULL)
//             return true;
        
//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);
        
//         bool diff = abs(height(root->left)-height(root->right))<=1;
        
//         if(left && right && diff)
//             return true;
//         else
//             return false;
//     }


// Approach 2 
// pair<bool,int> isBalancedFast(Node* root){
//             if(root==NULL){
//                 pair<bool,int> p = make_pair(true,0);
//                 return p;
//             }
            
//             pair<bool,int> left = isBalancedFast(root->left);
//             pair<bool,int> right = isBalancedFast(root->right);
            
//             bool leftAns = left.first;
//             bool rightAns = right.first;
            
//             bool diff = abs(left.second-right.second) <=1;
            
//             pair<bool,int> ans;
//             ans.second = max(left.second, right.second) + 1;
            
//             if(leftAns && rightAns && diff)
//                 ans.first =  true;
//             else
//                 ans.first = false;
            
//             return ans;
            
//         }
        
//         bool isBalanced(Node *root){
//             return isBalancedFast(root).first;
//         }





// To check whether 2 trees are idntical or not.
// bool isIdentical(Node *r1, Node *r2)
//     {
//         if(r1==NULL && r2==NULL)
//             return true;
        
//         if(r1==NULL && r2!=NULL)
//             return false;
        
//         if(r1!=NULL && r2==NULL)
//             return false;
        
//         bool root = (r1->data==r2->data);
//         bool left = isIdentical(r1->left,r2->left);
//         bool right = isIdentical(r1->right,r2->right);
        
//         if(left && right && root)
//             return true;
//         else
//             return false; 
//     }





// Q4: VERY IMPORATANT QUESTION -- TC: O[N], SC: O[H]
// Given a Binary Tree. Return true if, for every node X in the tree other than the leaves,
// its value is equal to the sum of its left subtree's value and its right subtree's value. Else return false.

// pair<bool,int> sumis(Node* root){
//     if(root == NULL){
//         pair<bool,int> p = make_pair(true,0);
//         return p;
//     }
    
//     if(root->left == NULL && root->right == NULL){
//         pair<bool,int> p = make_pair(true,root->data);
//         return p;
//     } 
    
//     pair<bool,int> left = sumis(root->left);
//     pair<bool,int> right = sumis(root->right);
    
    
//     bool leftAns = left.first;
//     bool rightAns = right.first;
    
    
//     pair<bool,int> ans;
//     if(rightAns && leftAns && (root->data == left.second+right.second)){
//         ans.first = true;
//         ans.second = 2*root->data;
//     }
//     else{
//         ans.first = false;
//     }
    
//     return ans;
// }

// bool isSumTree(Node* root)
//     {
//         return sumis(root).first;
//     }



// <-----------------------------------------------------TRAVERSALS--------------------------------------------------------------------->


// Q5: Zigzag traversal.
    // vector <int> zigZagTraversal(Node* root)
    // {
    // 	vector<int> result;
    // 	if(root==NULL)
    // 	    return result;

    // 	queue<Node *> q;
    // 	q.push(root);

    // To change direction we initialize ltr 
    //     bool ltr = true;
        
    // 	while(!q.empty()){
    // 	    int size = q.size();
    // 	    vector<int> ans(size);
        
    // Level processing......
    // 	    for(int i = 0;i<size;i++){
    // 	        Node * frontnode = q.front();
    // 	        q.pop();

    // 	        int index = ltr?i:size-i-1;
    // 	        ans[index] = frontnode->data;

    // 	        if(frontnode->left)
    // 	            q.push(frontnode->left);

    // 	        if(frontnode->right)
    // 	            q.push(frontnode->right);
    // 	    }

    // 	    for(auto i:ans)
    // 	        result.push_back(i);

    // changed direction
    // 	   ltr = !ltr;
    // 	}

    // 	return result;
    // }






// Q6. Boundary traversal .
// void traverseLeft(Node* root, vector<int> &ans) {
//         //base case
//         if( (root == NULL) || (root->left == NULL && root->right == NULL) )
//             return ;
            
//         ans.push_back(root->data);
//         if(root->left)
//             traverseLeft(root->left, ans);
//         else
//             traverseLeft(root->right, ans);
            
//     }
    
//     void traverseLeaf(Node* root, vector<int> &ans) {
//         //base case
//         if(root == NULL)
//             return ;
            
//         if(root->left == NULL && root->right == NULL) {
//             ans.push_back(root->data);
//             return;
//         }
        
//         traverseLeaf(root->left, ans);
//         traverseLeaf(root->right, ans);
        
//     }

//     void traverseRight(Node* root, vector<int> &ans) {
//         //base case
//         if( (root == NULL) || (root->left == NULL && root->right == NULL) )
//             return ;
        
//         if(root->right)
//             traverseRight(root->right, ans);
//         else
//             traverseRight(root->left, ans);
            
//         //wapas aagye
//         ans.push_back(root->data);
            
//     }
    
//     vector <int> boundary(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL)
//             return ans;
            
//         ans.push_back(root->data);
        
//         //left part print/store
//         traverseLeft(root->left, ans);
        
//         //traverse Leaf Nodes
        
//         //left subtree
//         traverseLeaf(root->left, ans);
//         //right subtree
//         traverseLeaf(root->right, ans);
        
//         //traverse right part
//         traverseRight(root->right, ans);
        
//         return ans;
        
        
//     }




// Q7. Vertical order traversal 
// vector<int> verticalOrder(Node *root)
//     {
//         // levelwise ans horizontal distance wise elements ko store karenge aur use jodeke ans m daal denge. 
//         map<int, map<int,vector<int> > > nodes;

//         queue< pair<Node*, pair<int,int> > > q;
//         vector<int> ans;
        
//         if(root == NULL)
//             return ans;
            
//         q.push(make_pair(root, make_pair(0,0)));
        
//         while(!q.empty()) {
//             pair<Node*, pair<int,int> > temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second.first;
//             int lvl = temp.second.second;
            
//             nodes[hd][lvl].push_back(frontNode->data);
            
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, make_pair(hd-1, lvl+1) ));
                
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, make_pair(hd+1, lvl+1)));
//         }
        
//         for(auto i: nodes) {
            
//             for(auto j:i.second) {
                
//                 for(auto k:j.second)
//                 {
//                     ans.push_back(k);
//                 }
//             }
//         }
//         return ans;
//     }




// Q8: Top View (If someone sees the tree from top).
// vector<int> topView(Node *root)
//     {
//         vector<int> ans;
//         if(root == NULL) 
//         {
//             return ans;
//         }
//         map<int,int> topNode;
//         queue<pair<Node*, int> > q;

//         q.push(make_pair(root, 0));

//         while(!q.empty()) {
//             pair<Node*, int> temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second;

//             //if one value is present for a HD, then do nothing (agar top m hd ki value nahi hogi tabhi store hoga..map end ko point karega).
//             if(topNode.find(hd) == topNode.end())
//                 topNode[hd] = frontNode -> data;

//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, hd-1));
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, hd+1));
//         }

//         for(auto i:topNode) 
//         {
//             ans.push_back(i.second);
//         }
//         return ans;
//     }




// Q9: Bottom View (If someone sees the tree from bottom...hd ka last element chahiye).
// vector <int> bottomView(Node *root) {
//         vector<int> ans;
//         if(root == NULL) 
//         {
//             return ans;
//         }
        
//         map<int,int> topNode;
//         queue<pair<Node*, int> > q;
        
//         q.push(make_pair(root, 0));
        
//         while(!q.empty()) {
//             pair<Node*, int> temp = q.front();
//             q.pop();
//             Node* frontNode = temp.first;
//             int hd = temp.second;
            
//             topNode[hd] = frontNode -> data;
                
//             if(frontNode->left)
//                 q.push(make_pair(frontNode->left, hd-1));
//             if(frontNode->right)
//                 q.push(make_pair(frontNode->right, hd+1));
//         }
        
//         for(auto i:topNode) 
//         {
//             ans.push_back(i.second);
//         }
//         return ans;
//     }



// Q10: Left View (level ka leftmost element store karna h)
// void solve(Node* root, vector<int> &ans, int level) {
//     //base case
//     if(root == NULL)
//         return ;
//     //we entered into a new level    
//     if(level == ans.size())
//         ans.push_back(root->data);
//     solve(root->left, ans, level+1);
//     solve(root->right, ans, level+1);
// }

// vector<int> leftView(Node *root)
// {
//    vector<int> ans;
//    solve(root, ans, 0);
//    return ans;
// }



// Q10: Right View 
// void solve(Node* root, vector<int> &ans, int level) {
//     //base case
//     if(root == NULL)
//         return ;
//     //we entered into a new level    
//     if(level == ans.size())
//         ans.push_back(root->data);

//     solve(root->right, ans, level+1);    
//     solve(root->left, ans, level+1);
// }
//     vector<int> rightView(Node *root)
//     {
//         vector<int> ans;
//         solve(root, ans, 0);
//         return ans;
//     }



// Q11: Diagonal Traversal (level aur root se horizontally kitna door h diff nikal k use vector m store krna h...fir ans m daal dena h)
// void traverse(Node* root,map<int,vector<int>> &m,int hd,int level){
//     if(root==NULL)
//         return;

//     int diff = level-hd;
//     m[diff].push_back(root->data);

//     traverse(root->left,m,hd-1,level+1);  
//     traverse(root->right,m,hd+1,level+1);
// }
// vector<int> diagonal(Node *root)
// {
//     vector<int> ans;
//     if(root==NULL)
//         return ans;
        
//     map<int,vector<int>> m;
//     traverse(root,m,0,0);
//     for(auto i: m){
//         for(auto j:i.second){
//             ans.push_back(j);
//         }
//     }  
//     return ans;
// }

// <------------------------------------------------------- Other Questions ------------------------------------------------------------->

// Q12: find the sum of all nodes on the longest path from root to leaf node.
// void solve(Node* root,int l,int s,pair<int,int> &ans){
//         if(!root)
//             return;
        
//         s+=root->data;
//         solve(root->left,l+1,s,ans);
//         solve(root->right,l+1,s,ans);
        
//         if(l>=ans.first){
//             ans = make_pair(l,s);
//         }
//     }
    
//     int sumOfLongRootToLeafPath(Node *root)
//     {
//         pair<int,int> ans = make_pair(0,0);
//         solve(root,0,0,ans);
//         return ans.second;
//     }




// Q13: To find lowest common ancestor in a binary tree. 
// Node* lca(Node* root ,int n1 ,int n2 )
//     {
//         if(root == NULL)
//         return NULL;
        
//         if(root->data==n1 || root->data==n2)
//             return root;
        
//         Node* leftAns = lca(root->left,n1,n2);
//         Node* rightAns = lca(root->right,n1,n2);
        
//         if(leftAns != NULL && rightAns != NULL)
//             return root;
        
//         else if(leftAns != NULL && rightAns == NULL)
//             return leftAns;
        
//         else if(leftAns == NULL && rightAns != NULL)
//             return rightAns;

//         else
//             return NULL;
//     }



//Q14: Kth ancestor of a node 
// Node* solve(Node* root, int &k, int node) {
//     //base case
//     if(root == NULL)
//         return NULL;

//     if(root->data == node) 
//     {
//         return root;
//     }

//     Node* leftAns = solve(root->left, k, node);
//     Node* rightAns = solve(root->right, k, node);


//     //wapas
//     if(leftAns != NULL && rightAns == NULL) 
//     {
//         k--;
//         if(k<=0) 
//         {
//             //answer lock
//             k = INT_MAX;
//             return root;
//         }
//         return leftAns;
//     }

//     if(leftAns == NULL && rightAns != NULL) {
//         k--;
//         if(k<=0) 
//         {
//             //answer lock 
//             k = INT_MAX;
//             return root;
//         }
//         return rightAns;
//     }
//     return NULL;

// }
// int kthAncestor(Node *root, int k, int node)
// {
//     Node* ans = solve(root, k, node);
//     if(ans == NULL || ans->data == node)
//         return -1;
//     else
//         return ans->data;
// }




// Q15: Maximum sum of non adjacent root (fix tarika h).
// pair<int,int> solve(Node* root) {
//         //base case
//         if(root == NULL) {
//             pair<int,int> p = make_pair(0,0);
//             return p;
//         }
        
//         pair<int,int> left = solve(root->left);
//         pair<int,int> right = solve(root->right);
        
//         pair<int,int> res;
        
//         res.first = root->data + left.second + right.second;
        
//         res.second = max(left.first, left.second) + max(right.first, right.second);
        
//         return res;
        
//     }
//     int getMaxSum(Node *root) 
//     {
//         pair<int,int> ans = solve(root);
//         return max(ans.first, ans.second);
//     }



// Q16: K - sum paths..(Total number of paths where sum is K)
// void solve(Node* root, int k, int &count, vector<int> path) {
//         //base case
//         if(root == NULL)
//             return ;

//         path.push_back(root->data);

//         //left
//         solve(root->left, k, count, path);
//         //right
//         solve(root->right, k, count, path);

//         //check for K Sum

//         int size = path.size();
//         int sum = 0;
//         for(int i = size-1; i>=0; i--)  {
//             sum += path[i];
//             if(sum == k)
//                 count++;
//         }

//         path.pop_back();  (OPTIONAL STEP)
//     }
//     int sumK(Node *root,int k)
//     {
//         vector<int> path;
//         int count = 0;
//         solve(root, k, count, path);
//         return count;
//     }

int main(){
    
    return 0;
}