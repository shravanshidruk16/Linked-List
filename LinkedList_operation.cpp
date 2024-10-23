
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

    void printLL(){ // to print the data elements from the list
        Node* temp= head;
        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<"NULL\n";
    }


    void push_front(int val){   // push the element from front
        Node* newNode = new Node(val);

        if(head==NULL){
            head=tail=newNode;


        }else{
            newNode->next=head;
            head = newNode;
        }
    }

    void push_back(int val){  // push the element from back
        Node* newNode = new Node(val);
        if(head==NULL){
            head=tail=newNode;

        }
        else{
            tail->next=newNode;
            tail=newNode;
        }
    }

    

    void Insert(int val, int pos){  // Insert data element at required position
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

    void pop_front(){ // remove the element from front 
        if(head==NULL){
            cout<<"LL is empty\n";
            return;
        }
        Node* temp= head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }

    int searchItr(int key){ // search the given key in LL and return the index
        Node* temp=head;
        int idx=0;
        while(temp!=NULL){
            if(temp->data==key){
                return idx;
            }
            temp=temp->next;
            idx++;
            
        }
        return -1;
    }

    int helper(Node* h , int key){ // this func is used to search through recursion
        if(h==NULL){
            return -1;
        }
        if(h->data==key){
            return 0;
        }
        int idx = helper(h->next,key);
        if(idx==-1){
            return -1;
        }
        return idx+1;
    }
    int searchRec(int key){  // the output of recursive function is stored here
        return helper(head, key);
    }

    void reverseLL(){  // to reverse the LL
        Node* curr=head;
        Node* prev=NULL;
        
        while(curr!=NULL){
            Node* next=curr->next;
            curr->next=prev;
            // now update curr and prev
            prev=curr;
            curr=next;
        }
        head=prev; /*from the above loop we get prev as last 
        element so when we reverse the ll then the prev(last element) 
        should be equal to head element of ll */
    }

    int Get_size(){  // to find the total data elements present in the linked list
        int sz=0;
        Node* temp = head;
        while(temp!=NULL){
            temp=temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){  // to remove Nth number element from backside of linked-list
        int size= Get_size();
        Node* prev=head;
        for(int i=1 ; i<(size-n); i++){
            prev=prev->next;
        }
        Node* toDel=prev->next;
        cout<<"The element going to be deleted is:"<<toDel->data<<endl;
        prev->next=prev->next->next;
    }

};

int main(){
    Lists ll;
    ll.push_front(3);
    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(4);
    ll.push_back(5);
    //ll.printLL();
    //ll.Insert(100,2);
    //ll.printLL();
    //ll.pop_front();
    //ll.printLL();
    //cout<<"Through iterative search:"<<ll.searchItr(100)<<endl;
    //cout<<"Through recursive search:"<<ll.searchRec(100)<<endl;
    // cout<<"The reversed LL is: "<<endl;
    //ll.reverseLL();
    ll.printLL(); // 1->2->3->4->5
    ll.removeNth(2);
    ll.printLL();

    return 0;
}
