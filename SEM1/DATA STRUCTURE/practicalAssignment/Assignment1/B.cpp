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
void rotate(vector<int> &array,int k){
    int n = array.size();
    stack<int> stk;
    k%=n;
    int i = n-1;
    while(k-->0){
        stk.push(array[i--]);
    }
    int end = n-1;
    while(i>=0){
        array[end--] = array[i--]; 
    }
    i = 0;
    while(stk.size()){
        array[i++] = stk.top();
        stk.pop(); 
    }
}
int main(){
    vector<int> array = {1, 2, 3, 4, 5};
    int k =2;
    display(array);
    rotate(array,k);
    display(array);
    return 0;
}