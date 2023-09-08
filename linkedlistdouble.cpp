#include <iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* prev;
        Node* next;

        // constructor 
        Node(int d){
            this -> data = d;
            this -> prev = NULL;
            this -> next = NULL;
        }

        // destructor 
        ~Node(){
            int val = this -> data;
            if (this->next!=NULL){
                delete next;
                next = NULL;
            }
            cout<< "Memeory free for node with data "<< val<<endl;
        }   
};

void print(Node* head){
            Node* temp = head;

            while (temp != NULL)
            {
                cout<<temp -> data<<"  ";
                temp = temp -> next;
            }
            cout<<endl;
        }



// Gives the length of the linked list 
int getLength(Node* head){
    int len = 0;
    Node* temp = head;

    while (temp != NULL)
    {
        len++;
        temp = temp -> next;
    }
    return len;
}


// Inserting at head 
void insertAtHead(Node* &tail,Node* &head,int d){
    // Empty list 
    if (head == NULL)
    {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{

    Node* temp = new Node(d);
    // new element k next ko head m point karwa do 
    temp -> next = head;

    // head k previous ko new element par point karwa denge 
    head -> prev = temp;
    head = temp;
    }
}

void insertAtTail(Node* &tail,Node* &head,int d){

    // Empty list 
    if (tail == NULL)
    {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
    // Create
    Node* temp = new Node(d);

    tail -> next = temp;
    temp -> prev =  tail;
    tail = temp;
    }
}


void insertAtPosition(Node* &tail,Node* &head,int position,int d){

    // Insert at start 
    if(position == 1){
        insertAtHead(tail,head,d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    while (cnt < position-1)
    {
        temp = temp -> next;
        cnt++;
    }
    
    // Inserting at the last position 
    if (temp -> next == NULL)
    {
        insertAtTail(tail,head,d);
        return ;
    }
    
    // Inserting at any other position 
    Node* nodeToInsert = new Node(d);

    // Adjusting all 4 pointers .
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;

    temp->next = nodeToInsert;
    nodeToInsert -> prev = temp;

}



// Deleting a node  
void deleteNode(int position,Node* &head,Node* &tail){
    
    // deleting first or start node .
    if (position == 1)
    {
        Node* temp = head;
        temp -> next -> prev = NULL;
        head  = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    // deleting at any other or last position .
    else
    {
    Node* curr = head;
    Node* prev = NULL;
    
    int cnt = 1;
    while (cnt<position)
    {
        prev = curr;
        curr = curr -> next;
        cnt++;
    }
    // If deletion is at the last.
    if (curr -> next == NULL)
    {
        tail = curr -> prev;
    }
    
    curr  -> prev = NULL;
    prev -> next = curr -> next;
    curr ->next = NULL;
    delete curr;
    }
}

int main(){
    // Node* node1 = new Node(10);
    Node* head = NULL;
    Node* tail = NULL;

    // cout<< getLength(head) <<endl;

    insertAtHead(tail,head,11);
    insertAtHead(tail,head,17);
    insertAtHead(tail,head,44);
    insertAtHead(tail,head,55);
    insertAtHead(tail,head,1);
    insertAtHead(tail,head,66);
    insertAtHead(tail,head,99);
    insertAtHead(tail,head,204);
    print(head);

    insertAtTail(tail,head,300);
    print(head);

    deleteNode(9,head,tail);
    print(head);
    cout<<tail->data;


    return 0;
}