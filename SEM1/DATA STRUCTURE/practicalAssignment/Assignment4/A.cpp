#include<iostream>
using namespace std;
class node{
    public :
        int data;
        node * next;
        node(int val){
            this->data = val;
            this->next = NULL;
        }
};
class SinglyLinkedList{
    private:
        node * head = NULL;
        int length = 0;
        node * add(node * &head,int val){
            if(head==NULL){
                return new node(val);
            }
            else{
                head->next = add(head->next,val);
                return head;
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
        node * reverse(node * &head,node * &prev){
            if(head==NULL){
                return prev;
            }
            node * temp = head;
            head = reverse(head->next,head);
            temp->next = prev;
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
    public:
        void add(int data){
            this->head = this->add(this->head,data);
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
        void reverse(){
            node * prev = NULL;
            this->head=this->reverse(this->head,prev);
        }
        void sort(){
            this->head = this->mergeSort(head);
        }

};
int main(){
    SinglyLinkedList obj;
    // obj.display();
    obj.add(45);
    obj.add(50);
    obj.add(20);
    obj.add(19);
    obj.add(1);
    obj.display();
    // obj.discard(4);
    // obj.reverse();
    obj.sort();
    obj.display();
    return 0;
}