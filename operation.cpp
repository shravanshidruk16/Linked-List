// In this program we will see how to push an element from front position and back position in the linked list
#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
public:
    Node(int val){
        data=val;
        next=NULL;
        
    }
};

class Lists{
public:
    Node* head;
    Node* tail;
    
    Lists(){
        head=NULL;
        tail=NULL;
    }
    void push_front(int val){
        Node* newNode = new Node(val);

        if(head==NULL){
            head=tail=newNode;


        }else{
            newNode->next=head;
            head = newNode;
        }
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;

        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    void printLL(){
        Node* temp= head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }

    void Insert(int val, int pos){
        Node* newNode=new Node(val);
        Node* temp = head;
        for(int i=0 ;i<pos-1;i++){
            if(temp==NULL){
                cout<<"Invalid Position"<<endl;
                return;
            }
            temp=temp->next;
            }
        // from the above for loop we will get temp at index pos-1
        newNode->next=temp->next;
        temp->next=newNode;
    }

    void pop_front(){
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node* temp= head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

};

int main(){
    Lists ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.printLL();
    ll.Insert(100,2);
    ll.printLL();
    ll.pop_front();
    ll.printLL();
    return 0;
}