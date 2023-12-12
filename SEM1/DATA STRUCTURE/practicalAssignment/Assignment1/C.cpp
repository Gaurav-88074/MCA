#include<iostream>
#include<vector>
#include<stack>
using namespace std;
void display(vector<int> &array){
    for(int i:array){
        cout<<i<<" ";
    }
    cout<<endl;
}
bool has(vector<int> &array,int key){
    for(int i: array){
        if(key==i)return true;
    }
    return false;
}
vector<int> getUnion(vector<int> &array1,vector<int> &array2){
    vector<int> res;
    for(int x : array1){
        if(!has(res,x))res.push_back(x);
    }
    for(int x : array2){
        if(!has(res,x))res.push_back(x);
    }
    return res;
}
int main(){
    vector<int> array1 = {10,20,30};
    vector<int> array2 = {20,30,40};
    vector<int> unionArray = getUnion(array1,array2);
    display(unionArray);
    return 0;
}