#include<iostream>
#include<vector>
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
vector<int> getIntersection(vector<int> &array1,vector<int> &array2){
    vector<int> res;
    for(int x : array1){
        if(has(array2,x))res.push_back(x);
    }
    return res;
}
int main(){
    vector<int> array1 = {10,20,30};
    vector<int> array2 = {20,30,40};
    vector<int> intersection = getIntersection(array1,array2);
    display(intersection);
    return 0;
}