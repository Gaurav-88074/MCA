#include<iostream>
using namespace std;
class Base1{
    public:
        Base1(){
            cout<<"I'm your base 1 ancestor"<<endl;
        }
        void greet(){
            cout<<"hii there 1"<<endl;
        }
};
class Base2{
    public:
        Base2(){
                cout<<"I'm your base 2 ancestor"<<endl;
            }
        void greet(){
            cout<<"hii there 2"<<endl;
        }
};
class Derived : public Base1,public Base2{
    public:
        int x;
        void greet(){
            // Base1::greet();
            cout<<"hey bebe"<<endl;
        }
};
int main(){
    Derived obj;
    obj.greet();  
    return 0;
}