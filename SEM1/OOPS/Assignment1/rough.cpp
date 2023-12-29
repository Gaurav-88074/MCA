#include<iostream>
using namespace std;
class A;
class B;
void swapValues(A &,B &);
class A{
    private :
        int num;
    public:
        A(int x){
            this->num = x;
        }
        void display(){
            cout<<"num : "<<this->num<<endl;
        }
        friend void swapValues(A &,B &);

};
class B{
    private :
        int num;
    public:
        B(int x){
            this->num = x;
        }
        void display(){
            cout<<"num : "<<this->num<<endl;
        }
        friend void swapValues(A &,B &);
};
void swapValues(A &obj1,B &obj2){
    int x = obj1.num;
    obj1.num = obj2.num;
    obj2.num = x;
}
int main(){
    A obj1(10);
    B obj2(20);
    obj1.display();
    obj2.display();
    swapValues(obj1,obj2);
    cout<<endl;
    obj1.display();
    obj2.display();
    return 0;
}