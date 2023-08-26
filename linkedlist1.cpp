#include <iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // constructor 
        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        // destructor 
        ~Node(){
            int value = this -> data;
            // Memory free. 
            if (this->next != NULL)
            {
                delete next;
                this -> next = NULL;
            }
            cout<< "Memory free " <<endl;
        }
};



void  insertAtHead(Node* &head, int d){
    // S1: Create new node 
    Node* temp = new Node(d);

    // S2: Temp k next ko pahle wale k head par point kar denge  
    temp->next = head;

    // S3: Head ko naye wale node k head par point kar denge 
    head =  temp;
}



void insertAtTail(Node* &tail, int d){
    // S1: Create new node
    Node* temp = new Node(d);

    // S2 & S3 
    // current tail ka jo next h matlab jo pointer h use next element yani temp par put karwa dia 
    tail -> next = temp;
    tail = tail -> next;
}



void InsertAtPosition(Node* &tail,Node* &head, int position,int d){

    // Insert at start 
    if (position == 1)
    {
        insertAtHead(head, d);
        return ;
    }

    Node* temp = head;
    int cnt = 1;

    // S1: Traverse karva ke us element k pehle tak le jana h 
    while (cnt<position-1)
    {
        temp  = temp ->next;
        cnt++;
    }

    // Inserting at last position 
    if(temp -> next == NULL){
        insertAtTail(tail,d);
        return ;
    }
    
    // S2: Craeting a new node for d 
    Node* nodeToInsert = new Node(d);

    // temp -> next matlab agle element h. nodeToInsert -> next ise point karege 
    nodeToInsert -> next =  temp -> next;
    temp -> next = nodeToInsert;
}



void deleteNode(int position, Node* &head){
    
    // Case 1: Deleting first node 
    if (position==1)
    {
        Node* temp = head;
        head = head -> next;
        // Memory free 
        // pointer ko hataenge element par se 
        temp -> next = NULL;
        delete temp;

    }
    // Case 2: Deleting any other node or last node. 
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while (cnt < position)
        {
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        
        prev -> next = curr -> next;
        curr -> next = NULL;
        delete curr;
        
    }
}


int getLength(Node *head){
    Node *temp = head;
    int cnt = 1;
    while (temp)
    {
        cnt++;
        temp=temp->next;
    }
    return cnt;
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



int main(){
    Node* node1 = new Node(10);
    // cout << node1 -> data <<endl;
    // cout << node1 -> next <<endl;

    // head pointed to node1 
    Node* head = node1;
    Node* tail = node1; 

    print(head);
    insertAtTail(tail, 12);

    // insertAtHead(head, 45);
    print(head);


    insertAtTail(tail,33);
    print(head);

    // Kisi position par object insert karne k lie 
    // InsertAtPosition(tail,head,4,1003);
    // print(head);

    // cout << "Head -" << head -> data <<" Tail - "<< tail -> data << endl;

    // deleteNode(4,head);
    // print(head);

    // cout << "Head -" << head -> data <<" Tail - "<< tail -> data << endl;



    return 0;
}