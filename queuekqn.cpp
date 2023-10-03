#include <bits/stdc++.h>
using namespace std;

class Kqueue{
    public:
        int n;
        int k;
        int *front;
        int *rear;
        int *arr;
        int freespot;
        int *next;

    public:
    Kqueue(int n,int k){
        this->n = n;
        this->k = k;
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
        {
            front[i] = -1;
            rear[i] = -1;
        }
        
        next = new int[n];
        for (int i = 0; i < n; i++)
        {
            next[i] = i+1;
        }
        next[n-1] = -1;

        arr = new int[n];
        freespot = 0;
    }



    void enqueue(int data, int qn){
        // S1: Overflow check karna h 
        if(freespot==-1){
            cout<<"No empty space present"<<endl;
            return;
        }

        // S2: find the first free index 
        int index = freespot;

        //S3: update freespot 
        freespot = next[index];

        // S4: check whether free element 
        if(front[qn-1] == -1)
            front[qn-1] = index;
        else{
            // link new element to previous element 
            next[rear[qn-1]] = index;
        }
        
        // S5: 
        // update next to -1 to push next time
        next[index] = -1;

        // update rear to current element 
        rear[qn-1] = index;

        // push element 
        arr[index] = data;
    }


    int dequeue(int qn){
        // underflow 
        if(front[qn-1] == -1){
            cout<<"Queue Underflow"<<endl;
            return;
        }

        // find index to pop 
        int index = next[qn-1];

        // front ko aage badha dena h 
        front[qn-1] = next[index];

        // freespots ko manage karo 
        next[index] = freespot;
        freespot = index; 
        
        return arr[index];
    }

};





int main(){
    
    return 0;
}