#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node* next;
    node(int data){
        this->data=data;
        this->next=next;
    }
    ~node(){
        if(this->next!=NULL){
            this->next=NULL;
            delete next;
        }
    }
};

void print(node* &head)
    {
        node* temp=head;
        while(temp){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    
void insertathead(int data,node* &head){
    node* newnode=new node(data);
    if(head==NULL){
        head=newnode;
    }
    else{
        newnode->next=head;
        head=newnode;
    }
}

void insertattail(int data,node* &head){
    node* newnode=new node(data);
    node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    temp->next=newnode;
}

void insertatany(int data,node* &head,int pos){
    node* newnode=new node(data);
    if(pos==1){
        insertathead(data,head);
    }
    else{
        node* temp=head;
        for(int i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
}

void deletenode(node* &head,int pos){
    if(pos==1){
       node* temp=head;
       head=temp->next;
       delete temp;
    }
    else{
        node* prev=NULL;
        node* curr=head;
        for(int i=1;i<pos;i++){
        prev=curr;
        curr=curr->next;
    }
        prev->next=curr->next;
        delete curr;
    }
    
    
}
int main(){
    node* newnode=new node(10);
    node* head=newnode;
    insertathead(5,head);
    insertattail(15,head);
    insertatany(20,head,4);
    insertatany(110,head,3);
    deletenode(head,3);
    print(head);
    
    
    return 0;
}