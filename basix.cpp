// this is the basic structure of ll 

#include <iostream>
using namespace std;

class Node{
    int data;
    Node* next; // this next points to the memory address of nxt element
public:
    Node(int val){
        data=val;
        
    }
};

class Lists{
    Node* head;
    Node* tail;
    Lists(){
        head=NULL;
        tail=NULL;
    }
};

int main(){
    Lists ll();
    return 0;
}