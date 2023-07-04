#include <iostream>
#include <string>
using namespace std;

union employee
{
    int eId;
    char favChar;
    int salary;
};

int main(){
    union employee Vikas;
    Vikas.eId = 22;
    Vikas.favChar = 'd';
    Vikas.salary = 8000;
    return 0;
}