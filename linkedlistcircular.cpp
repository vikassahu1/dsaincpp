#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
    
    // constructor 
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    // Destructor 
    ~Node() {
        int value = this -> data;
        if (this -> next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout<< "Memory is free for node with data " << value << endl;
    }
};

// Only tail is required no need to make head 


void insertNode(Node* &tail,int element,int d){

    // Empty list 
    if (tail == NULL)
    {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode -> next = newNode;
    }
    else
    {
        // Non-empty list 
        // assuming that the element is present in the last 

        Node* curr = tail;

        while (curr -> data != element)
        {
            curr = curr -> next;
        }
        // element found 
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}



void print(Node* tail){
    Node* temp = tail;

    if (tail == NULL)
    {
        cout << "List is empty"<<endl;
    }
    

    do
    {
        cout << tail->data <<" ";
        tail = tail -> next;
    } while (tail != temp);
    cout<<endl;
}


void deleteNode(Node* &tail,int value){
    if (tail==NULL)
    {
        cout << "List is empty" << endl;
        return ;
    }
    else{
        // Non empty 

        // assuming that value is present in the linked list 
        Node* prev = tail;
        Node* curr = prev -> next;

        while (curr -> data != value)
        {
            prev = curr;
            curr = curr -> next;
        }
        
        prev -> next = curr -> next;

        // 1 Node linked list 
        if (curr == prev)
        {
            tail = NULL;
        }
        
        else if (tail == curr)
        {
            // FRONTMOST ELEMENT
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

int main(){
    
    Node* tail = NULL;
    insertNode(tail,5,9);
    insertNode(tail,9,9);
    insertNode(tail,9,100);
    print(tail);
    return 0;
}