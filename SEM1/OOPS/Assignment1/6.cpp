#include<iostream>
using namespace std;

class Complex;
Complex add(Complex &,Complex &);

class Complex{
    private:
        int i;
        int j;
    public:
        Complex(int i,int j){
            this->i = i;
            this->j = j;
        }
        void display(){
            cout<<i<<" + "<<j<<"i"<<endl;
        }
        friend Complex add(Complex &,Complex &);
};
Complex add(Complex &obj1,Complex &obj2){
    return Complex(obj1.i+obj2.i,obj1.j+obj2.j);
}
int main(){
    Complex obj1(1,2);
    Complex obj2(3,4);
    obj1.display();
    obj2.display();
    
    Complex res = add(obj1,obj2);
    res.display();

    return 0;
}