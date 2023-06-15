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
        while(temp->next!=head){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    


void insertatany(int data,node* &head,int pos){
    if(head==NULL){
        node* newnode=new node(data);
        newnode->next=newnode;
        head=newnode;
    }
    if(pos==1){
        node* newnode=new node(data);
        node* temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        head=newnode;
        
    }
    else{
        node* temp=head;
        node* newnode=new node(data);
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
            node* temp2=head;
            while(temp->next!=head){
                temp=temp->next;
            }
            temp->next=head->next;
            
            head=head->next;
            delete temp2;
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
    node* head=NULL;
    insertatany(20,head,1);
    insertatany(30,head,2);
    insertatany(40,head,3);
    insertatany(50,head,4);
    insertatany(60,head,5);
    deletenode(head,3);
    print(head);
    
    
    return 0;
}