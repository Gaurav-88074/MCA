#include<iostream>
using namespace std;
class Product{
    private:
        int itemId;
        string itemName;
        static int objCount;
    public:
        Product(int itemId,string itemName){
            this->itemId = itemId;
            this->itemName =itemName;
            this->objCount+=1;
        }
        static int showCount(){
            return objCount;
        }
};
int Product::objCount = 0;
int main(){
    Product obj1(1001,"RTX 3060");
    Product obj2(1002,"GTX 1660TI");
    int res = Product::showCount();
    cout<<"Object Count -> "<<res<<endl;
    return 0;
}