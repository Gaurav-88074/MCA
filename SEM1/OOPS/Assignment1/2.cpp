#include<iostream>
#include<map>
using namespace std;
class store{
    private:
        map<int,int> hashmap;
    public:
        void insert(int code,int value){
            hashmap[code] = value;
        }
        void discard(int code){
            hashmap.erase(code);
        }
        int getTotal(){
            int res=0;
            for(auto x : hashmap){
                res+=x.second;
            }
            return res;
        }
};
int main(){
    store s;
    s.insert(1007,22);
    s.insert(1008,42);
    cout<<s.getTotal()<<endl;
    return 0;
}