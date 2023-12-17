#include<iostream>
using namespace std;
class node{
    public :
        int data;
        node * next;
        node * prev;
        node(int val){
            this->data = val;
            this->next = NULL;
            this->prev = NULL;
        }
};
class DoublyLinkedList{
    private:
        node * head = NULL;
        node * tail = NULL;
        int length = 0;
        node * addLast(node * &head,node * &tail,int val){
            if(head==NULL && tail==NULL){
                // cout<<"true " <<val<<endl;
                node *toAdd = new node(val);
                this->head = toAdd;
                this->tail = toAdd;
                return this->head;
            }
            else{
                node * toAdd = new node(val);
                this->tail->next = toAdd;
                toAdd->prev = this->tail;
                this->tail = toAdd;
                return this->head;
            }
        }
        node * insert(node * &head,int val,int pos){
            if(head==NULL){
                return new node(val);
            }
            else if(pos==0){
                node * toAdd = new node(val);
                toAdd->next = head;
                return toAdd;
            }
            else{
                head->next = insert(head->next,val,pos-1);
                return head;
            }
        }
        node * discard(node * &head,int pos){
            if(head==NULL){
                return head;
            }
            else if(pos==0){
                return head->next;
            }
            else{
                head->next = discard(head->next,pos-1);
                return head;
            }
        }
        node * reverse(node * &head,node * &lastHead){
            if(head==NULL){
                return lastHead;
            }
            node * temp = head;
            head = reverse(head->next,head);
            // temp->next = prev;
            return head;
        }
        node * merge(node * &head1,node * &head2){
            if(head1==NULL){
                return head2;
            }
            if(head2==NULL){
                return head1;
            }
            if(head1->data < head2->data){
                head1->next = merge(head1->next,head2);
                return head1;
            }
            else{
                head2->next = merge(head1,head2->next);
                return head2;
            }
        }
        node * mergeSort(node * &head){
            if(head==NULL || head->next==NULL){
                return head;
            }
            node * mid=head;
            node * temp = head;
            node * midPre = head;
            while(temp!=NULL && temp->next!=NULL){
                temp=temp->next->next;
                midPre =mid;
                mid = mid->next;
            }
            midPre->next = NULL;
            node * left = mergeSort(head);
            node * right= mergeSort(mid);
            return merge(left,right);
        }
        void display(node * &head){
            if(head==NULL){
                cout<<"NULL"<<endl;
                return;
            }
            cout<<head->data<<"->";
            display(head->next);
        }
        void displayReverse(node * &tail){
            if(tail==NULL){
                cout<<"NULL"<<endl;
                return;
            }
            cout<<tail->data<<"->";
            displayReverse(tail->prev);
        }
    public:
        void addLast(int data){
            this->head = this->addLast(this->head,this->tail,data);
            this->length+=1;
        }
        int size(){
            return this->length;
        }
        void insert(int pos,int val){
            this->head = this->insert(this->head,val,pos);
            this->length+=1;
        }
        bool isEmpty(){
            return this->head==NULL;
        }
        void discard(int pos){
            this->head = discard(this->head,pos);
        }
        void display(){
            this->display(this->head);
        }
        void displayReverse(){
            this->displayReverse(this->tail);
        }
        void reverse(){
            node * prev = NULL;
            this->head=this->reverse(this->head,prev);
        }
        void sort(){
            this->head = this->mergeSort(head);
        }

};
int main(){
    DoublyLinkedList obj;
    // obj.display();
    obj.addLast(45);
    obj.addLast(50);
    obj.addLast(20);
    obj.addLast(19);
    obj.addLast(1);
    obj.display();
    // obj.displayReverse();
    // obj.discard(4);
    // obj.sort();
    // obj.display();
    return 0;
}