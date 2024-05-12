#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    auto sum = [&](int a,int b){
        return a+b;
    };
    auto display = [&](vector<int> &arr){
        for(int &x:arr){
            cout<<x<<" ";
        }
        cout<<endl;
    };
    auto comp = [&](int &a,int &b){
        return (a-b) < 0;
    };
   vector<int> arr = {1,4,2,0};
   sort(arr.begin(),arr.end(),comp);
   display(arr);
    return 0;
}