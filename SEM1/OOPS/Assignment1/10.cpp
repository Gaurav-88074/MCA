#include<iostream>
using namespace std;

class Complex{
    private:
        int i;
        int j;
    public:
        Complex(int i,int j){
            this->i = i;
            this->j = j;
        }
        Complex  operator+(Complex &that){
            return Complex(i+that.i,j+that.j);
        }
        // 3+2i
        // 1+i
        Complex  operator*(Complex &that){
            int a = this->i * that.i;
            int b = this->i * that.j +  this->j * that.i;
            int c = -(this->j * that.j); 
            return Complex(a+c,b);
        }
        void display(){
            cout<<i<<" + "<<j<<"i"<<endl;
        }
};
int main(){
    Complex obj1(1,2);
    Complex obj2(3,4);
    
    obj1.display();
    obj2.display();
    
    Complex res1 = obj1+obj2;
    cout<<"Addition : ";
    res1.display();

    Complex res2 = obj1*obj2;
    cout<<"Multiplication : ";
    res2.display();

    return 0;
}