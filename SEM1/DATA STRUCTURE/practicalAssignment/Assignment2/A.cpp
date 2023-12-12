#include<iostream>
#include<vector>
#include<set>
using namespace std;
void display(vector<int> &array){
    for(int i:array){
        cout<<i<<" ";
    }
    cout<<endl;
}
void removeDuplicate(vector<int> &array){
    vector<int> res;
    set<int> s;
    for(int i:array){
        if(s.find(i)==s.end()){
            res.push_back(i);
            s.insert(i);
        }
    }
    array=res;
}
int main(){
    vector<int> array = {1,2,3,3,4};
    display(array);
    removeDuplicate(array);
    display(array);
    return 0;
}