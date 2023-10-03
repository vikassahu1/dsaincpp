#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>

using namespace std;

class Node{
    public:
        int data;
        Node * next;

        // contructor 
        Node(int d){
            this -> data = d;
            this -> next = NULL;
        }

        // ~Node(){
        //     if (this->next != NULL)
        //     {
        //         delete next;
        //         this -> next = NULL;
        //     }
        // }
};



Node* reverse1(Node* head){

    // Base case 
    if (head == NULL || head ->next == NULL)
    {
        return head;
    }
    Node* chota = reverse1(head -> next);

    head -> next -> next = head;
    head -> next = NULL; 

    return chota;
}





void rev(Node* &head,Node* &curr,Node* &prev){

    if(curr==NULL){
        head = prev;
        return ;
    }

    Node * forward = curr -> next;
    rev(head,forward,curr);
    curr -> next = prev;

}

void reverseRecursion(Node* &head){
    Node * curr = head;
    Node * prev = NULL;
    rev(head,curr,prev); 
}





Node * reverseRecursion2(Node* &head){
    return reverse1(head);
}

void reverse(Node* &head){
    Node *curr = head;
    Node * prev = NULL;
    Node *forward = NULL;

    while (curr)
    {
        forward = curr -> next;
        curr -> next= prev;
        prev = curr;
        curr = forward;
    }
    head = prev;
}

void print(Node* &head){
    Node* temp = head;

    while (temp!=NULL)
    {
        // current node ki value print 
        cout<< temp -> data << " ";

        // temp ko aage badha dena h 
        temp = temp->next;
    }
    cout<<endl;
}

void  insertAtHead(Node* &head, int d){
    Node* temp = new Node(d); 
    temp->next = head;
    head =  temp;
}



int getLength(Node* head){
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}



void getMiddle(Node* head,int len){
    Node *temp = head;
    int cnt = 1;
    while (cnt<(len/2+1))
    {
        cnt++;
        temp = temp -> next;
    }
    cout << temp -> data << endl;
}



void getMiddle2(Node* head){
    if (head == NULL || head -> next == NULL)
    {
        cout<< head;
    }
    if(head->next->next == NULL){
        cout<< head -> next;
    }
    Node* slow = head;
    Node* fast = head -> next;

    while (fast)
    {
        fast = fast->next;
        if (fast)
        {
            fast = fast->next;
        }
        
        slow = slow -> next;
    }
    cout<<slow->data;
    
}



Node* kReverse(Node* head,int k){

    // base case 
    if (head == NULL)
    {
        return NULL;
    }
    
    // step1: reverse first k nodes 
    Node * next =NULL;
    Node * curr = head;
    Node* prev = NULL;
    int count = 0;

    while (curr!=NULL && count < k)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    // s2: Baaki ka recursion kar lega 
    if(next  != NULL){
        head -> next = kReverse(next,k);
    }
    return prev;
}


// To detect loop in linked list 

// Floyd cycle detecction 
bool detectLoop(Node* head)
    {
        Node *slowPointer = head,
             *fastPointer = head;

        while (slowPointer != NULL
            && fastPointer != NULL
            && fastPointer->next != NULL) {
            slowPointer = slowPointer->next;
            fastPointer = fastPointer->next->next;
            if (slowPointer == fastPointer)
                return 1;
        }
        return 0;
    }


bool detectLoop2(Node* head){
    if(head==NULL)
        return false;
    
    map<Node*,bool>visited;

    Node* temp = head;
    while (temp)
    {
        // Cycle is present 
        if (visited[temp]==true)
        {
            return 1;
        }
        visited[temp]=true;
        temp = temp->next;
    }
    return 0;
}


// Starting node of any loop present in the linked list using floyd cycle detection .

Node* startingNode(Node* head){
    Node * fast = head;
    Node * slow = head;
    Node * temp =  NULL;
    if (head==NULL)
        return head;

    int mark = 0;
    while (slow != NULL && fast != NULL)
    {
        fast = fast->next->next;
        slow = slow ->next;
        if (fast==slow)
        {
            mark=1;
            temp = fast;
            break;
        }
    }
    // slow = head krke loop chala deni h loop ke starting element par pahucha dega. 
    slow = head;

    while (slow!=temp)
    {
        slow = slow->next;
        temp = temp -> next;
    }
    cout<<slow->data<<endl;
    return slow;
}


// Removing any loop in the linked list using floyd cycle detection. 

void removeLoop(Node* head){
    if(head==NULL)
        return;
    
    Node *startNode = startingNode(head);
    Node* temp = startNode;
    while (temp->next!=startNode)
    {
        temp = temp->next;
    }
    temp->next = NULL;
}


// Removing duplicate elements from a sorted linked list 

void removeDuplicates(Node *&head){
    Node *curr = head;
    
    while (curr)
    {
        if(curr->next && curr->data == curr->next->data)
        {
            Node *toDelete = curr->next;
            curr->next = curr->next->next;
            delete toDelete;
        }
        else
        curr = curr->next;
    }
}

// Removing duplicate elements from an unsorted sorted linked list . 

// Approach 1: Using map. 
void removeDuplicates2(Node* &head){
    map<int,bool> duplicate;
    Node* temp = head;
    Node* prev = NULL;
    while (temp->next)
    {
        if (duplicate[temp->data] == true)
        {
            prev->next = temp->next;
            Node* toDelete = temp;
            temp = temp->next; 
            delete toDelete;
        }
        else{
        duplicate[temp->data] = true;
        prev = temp;
        temp = temp->next;
        }
    }
}



//  Merging two sorted linked list
Node * solve(Node* &first,Node* &second){

    // if only on element is present in first list.
    if (first->next==NULL)
    {
        first->next = second;
        return first;
    }
    


    Node * curr1 = first;
    Node * next1 = first -> next;
    Node * curr2 = second;
    Node * next2 = second -> next;

    while (next1!=NULL && curr2!=NULL)
    {
        // agar beech m aa raha h to insert karna h 
        if ((curr2->data >= curr1->data) && (curr2->data <= next1->data))
        {
            curr1->next=curr2;
            next2 = curr2->next; 
            curr2->next = next1;

        curr1 = curr2;
        curr2 = next2;
        }
        else{
            // curr 1 and next 1 ko aage badhana padega 
            curr1 = next1;
            next1 = next1->next;

            if (next1==NULL)
            {
                curr1->next = curr2;
                return first;
            }
            
        }
    }
    
}


Node* sortTwoList(Node* first,Node* second){
    if(first ==NULL)
        return second;
    if(second==NULL)
        return first;
    
    if(first->data <= second->data)
        solve(first,second);
    else
        solve(second,first);
}

// To check a linked list is palindrome or not

// Appraoch1: Using array. 
bool checkPlaindrome(Node* head){
    Node* temp = head;
    vector<int> a;
    while (temp)
    {
        a.push_back(temp->data);
        temp=temp->next;
    }
    int size = a.size();
    for (int i = 0,j=size-1; i < size,j>=0; i++,j--)
    {
        if (a[i]!=a[j])
        {
            return false;
        }
    }
    return true;
}

// Approach2: With space complexity O[1] (optimal solution)
Node *getMid(Node* head){
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node * reverseit(Node* head){
    Node* curr = head;
    Node* prev = NULL;
    Node* next = NULL;

    while (curr)
    {
        next = curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

// TC O[N], SC O[1]
bool checkPlaindrome2(Node* head){
    if (head->next == NULL)
        return true;
    
    // Step1: to find middle element.
    Node* middle = getMid(head);

    // Step2: Reverse the list after middle. 
    Node *temp = middle->next;
    middle->next = reverseit(temp);

    // Step3: Ab dono half ko compare karlo.
    Node* head1 = head;
    Node* head2 = middle->next;
    while (head2!=NULL)
    {
        if (head1->data!=head2->data)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    // Fir se reverse karna h (Optional)
    temp = middle->next;
    middle->next = reverseit(temp);
    return true;
}



// Adding two numbers using linked list 
// Reverse karke add kar dena h fir wapas reverse kar dena h.
// ek carry bhi rakhna h jo update hoga.




// To clone a linked list with an additional random pointer
void inserAtTail(Node *&head, Node *&tail, int data)
{
    Node *temp = new Node(data);
    if (head == NULL)
    {
        head = temp;
        tail = temp;
    }
    else
    {
        tail->next = temp;
        tail = temp;
    }
}
// First execute function 
Node *copyList(Node *head)
{
    // S1: Create a clone list
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;

    Node *temp = head;

    while (temp)
    {
        inserAtTail(cloneHead, cloneTail, temp->data);
        temp = temp->next;
    }

    // To get the random mapping in the clone 
    // S2: Create a map
    unordered_map<Node *, Node *> oldToNew;
    Node *originalNode = head;
    Node *cloneNode = cloneHead;

    while (originalNode)
    {
        oldToNew[originalNode] = cloneNode;
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }
    
    // S3: To set the random linked list. 
    originalNode = head;
    cloneNode = cloneHead;

    while(originalNode)
    {
        // cloneNode->arb = oldToNew[originalNode->arb];
        originalNode = originalNode->next;
        cloneNode = cloneNode->next;
    }

    return cloneHead;
}
// Note: Without map ke bhi ho sakta h pointers ke saath khel ke.





// Merge sort of linked list TC O[NlogN] SC O[logN]
Node *  getMid(Node* head){
    Node* slow = head;
    Node* fast = head->next;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node * merge(Node* &left,Node* &right){
    if(left==NULL)
        return right;

    if(right==NULL)
        return left;
    
    // Temporary Node bana k usme -1 store kar dia 
    Node *ans = new Node(-1);
    Node *temp = ans;

    // ans ke aage sab sort krkr laga denge 
    while(left && right){
        if(left->data<right->data){
            temp ->next= left;
            temp = left;
            left = left->next;
        }
        else{
            temp ->next= right;
            temp = right;
            right = right->next;
        }
    }
    while(left){
        temp ->next= left;
        temp = left;
        left = left->next;
    }
    while(right){
        temp ->next= right;
        temp = right;
        right = right->next; 
    }
    // ans->next karne se wo -1 wali value consider nhi hogi 
    ans = ans->next;

    return ans;
}

Node* mergeSort(Node *head) {
    
    // base case 
    if(head==NULL || head->next==NULL)
        return head;

    // s1: mid nikalna h 
    Node * mid = getMid(head);
    Node *left = head;
    // break linked list into two halves 
    Node * right = mid->next;
    mid->next = NULL;

    // recursive call se left and right part ko sort karna h 
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge kar dena h 
    Node * result = merge(left,right);

    return result;
}



int main(){
    Node* node1 = new Node(5); 
    Node* head = node1;
    insertAtHead(head,1);
    insertAtHead(head,1);
    insertAtHead(head,5);
    // insertAtHead(head,5);
    // insertAtHead(head,9);
    // insertAtHead(head,2);
    // insertAtHead(head,1);
    // insertAtHead(head,7);
    print(head);
    // Node * head2 = reverseRecursion2(head);
    // print(head2);

    // getMiddle(head,getLength(head));
    // getMiddle2(head);

    // Node* lund = kReverse(head,3);
    // print(lund);

    // cout<<detectLoop2(head)<<endl;
    // cout<<detectLoop(head)<<endl;

    // removeDuplicates(head);
    // print(head);
    cout<<checkPlaindrome(head)<<endl;
    return 0;
}