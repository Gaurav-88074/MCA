#include<iostream>
using namespace std;
class A;
class B;
int getMax(A,B);
class A{
    private :
        int num;
    public:
        A(int _){
            this->num = _;
        }
        friend int getMax(A,B);
};
class B{
    private :
        int num;
    public:
        B(int _){
            this->num = _;
        }
        friend int getMax(A,B);
};
int getMax(A obj1,B obj2){
    return max(obj1.num,obj2.num);
}
int main(){
    A obj1(10);
    B obj2(20);
    cout<<getMax(obj1,obj2)<<endl;
    return 0;
}