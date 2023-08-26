#include <iostream>
#include <bits/stdc++.h>
#include <map>

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

        ~Node(){
            if (this->next!=NULL){
                delete next;
                next = NULL;
            }
        }
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
    while (curr!=NULL)
    {
        if ((curr->next!=NULL) && curr->data == curr->next->data)
        {
            Node* nex = curr->next->next;
            Node *toDelete = curr->next;
            delete toDelete;
            curr->next = nex;
        }
        else{
            curr = curr->next;
        }
    }
}

// Removing duplicate elements from an unsorted sorted linked list . 
void removeDuplicates2(Node* head){
    
}


int main(){
    Node* node1 = new Node(5); 
    Node* head = node1;
    insertAtHead(head,5);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
    insertAtHead(head,4);
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

    removeDuplicates(head);
    print(head);
    return 0;
}