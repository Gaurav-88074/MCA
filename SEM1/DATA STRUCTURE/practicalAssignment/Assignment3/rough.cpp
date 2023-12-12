#include<iostream>
using namespace std;
class node{
    public : 
        int data;
        node * next;
        node(int val){
            this->data =val;
            this->next =NULL;
        }
};
void display(node * head){
    if(!head){
        cout<<"NULL"<<endl;
        return;
    }
    cout<<head->data<<"->";
    display(head->next);
}
node * insert(node * head,int val){
    if(head==NULL){
        return new node(val);
    }
    else if (head->data>val){
        node * toAdd = new node(val);
        toAdd->next = head;
        return toAdd;
    }
    else{
        head->next  = insert(head->next,val);
        return head;
    }
    
}
int main(){
    node * head = NULL;
    head = insert(head,10);
    head = insert(head,5);
    head = insert(head,2);
    head = insert(head,1);
    display(head);

    return 0;
}