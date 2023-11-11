#include <bits/stdc++.h>
using namespace std;

// Q1: To find Kth smallest element from an array (l & r are start and end index)
int kthSmallest(int arr[], int l, int r, int k){

    // S1: Make max heap till k elements (Agar largest element bola to min heap karke nikal lenge)
    priority_queue<int> pq;
    for (int i = 0; i < k; i++)
        pq.push(arr[i]);
    
    // S2: Compare if any element from k to end is smaller than this then push if into queue after poping maximum one 
    for (int i = k; i <=r ; i++)
    {
        if(arr[i]<pq.top()){
            pq.pop();
            pq.push(arr[i]);
        }
    }
    
    // S3: Return ans. 
    int ans = pq.top();
    return ans;
}




// Q2: Check given bt is heap or not (VERY IMPORTANT)
// int countNode(struct Node*root){
//         if(root==NULL)
//             return 0;
        
//         int ans = 1 + countNode(root->left) + countNode(root->right);
//         return ans;
//     }
    
    
    
//     bool isCBT(struct Node* root, int index, int cnt){
//         if(root==NULL)
//             return true;
        
//         // agar index total number of node se jyada hoga to false h 
//         if(index >= cnt)
//             return false;
//         else{
//             bool left = isCBT(root->left,2*index+1,cnt);
//             bool right = isCBT(root->right,2*index+2,cnt);
//             return (left && right);
//         }
//     }

//     bool isMaxorder(struct Node* root){
//         // c1: Leaf node hoga
//         if(root->left==NULL && root->right==NULL)
//             return true;
        
//         // c2: right part nhi hoga
//         if(root->right==NULL){
//             return (root->data > root->left->data);
//         }
        
//         // c3: dono child honge 
//         else{
//             bool left = isMaxorder(root->left);
//             bool right = isMaxorder(root->right);
            
//             return (left && right && (root->data > root->left->data && root->data > root->right->data));
//         }
//     }
    
//     bool isHeap(struct Node* tree) {
//         int index = 0;
//         int totalCount = countNode(tree);
        
//         // Complete binary tree hona chahiye aur child chhote hone chahiye parent se
//         if(isCBT(tree, index, totalCount) && isMaxorder(tree))
//             return true;
//         else
//             return false;
//     }


// Q3: Kth largest sum of subarray. 
int getKthLargest(vector<int> &arr, int k)
{
	priority_queue<int,vector<int>,greater<int>> pq;

	int n = arr.size();
	for(int i=0;i<n;i++){
		int sum = 0;
		for(int j=i;j<n;j++){
			sum+=arr[j];
			if(pq.size()<k){
				pq.push(sum);
			}
			else{
				if(sum>pq.top()){
					pq.pop();
					pq.push(sum);
				}
			}
		}
	}
	return pq.top();
}


// Q4: Merge K sorted arrays 
vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> minHeap;
    
	// Saare first elements push kar denge uske baad commpare kar lenge 
    for(int i=0;i<kArrays.size();i++)
        minHeap.push({kArrays[i][0],{i,0}});

    while(!minHeap.empty()){
        pair<int,pair<int,int>> curr = minHeap.top();
        minHeap.pop();

        ans.push_back(curr.first);

        int i = curr.second.first;
        int j = curr.second.second;

        if(j+1<kArrays[i].size()){
            minHeap.push({kArrays[i][j+1],{i,j+1}});
        }
    }
    return ans;
}


// Q4: Merge K sorted linked lists. 
// class compare{
//     public:
//     bool operator()(Node* a, Node* b){
//         return a->data>b->data;
//     }
// };
// Node* mergeKLists(vector<Node*> &listArray){
//     priority_queue<Node*,vector<Node*>,compare> minHeap;
//     int k = listArray.size();
//     if(k==0) 
//         return NULL;

//     // S1
//     for(int i=0;i<k;i++)
//         minHeap.push(listArray[i]);    
    
//     Node* head = NULL;
//     Node* tail = NULL;

//     while(!minHeap.empty()){
//         Node* top = minHeap.top();
//         minHeap.pop();

//         if(top->next!=NULL)
//             minHeap.push(top->next);

//         if(head==NULL){
//             head = top;
//             tail = top;
//         }
//         else{
//             tail->next = top;
//             tail = top;
//         }
//     }
//     return head;
// }


int main(){
    
    return 0;
}