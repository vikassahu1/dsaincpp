#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Hero{
    public:
        char *name;
        int health;

    Hero(int health,char name[]){
        this->health = health;
        this->name = name;
    }
};


int main(){
    // Static allocation 
    Hero a(3,"Vikas");

    // Dynamic Allocation 
    // Hero *b = new Hero;
    return 0;
}
