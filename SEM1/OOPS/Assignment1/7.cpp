#include<iostream>
using namespace std;
class Product{
    private:
        int itemId;
        string itemName;
    public:
        Product(int itemId,string itemName){
            this->itemId = itemId;
            this->itemName =itemName;
        }
        void display(){
            cout<<this->itemId<<" "<<this->itemName<<endl;
        }
};

int main(){
    Product obj1(1001,"RTX 3060");
    Product obj2(obj1);
    // obj1.display();
    obj2.display();
    return 0;
}