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
void reverse(vector<int> &array){
    int n = array.size();
    for(int i =0;i< n/2 ;i++ ){
        swap(array[i],array[n-i-1]);
    }
}
int main(){
    vector<int> array = {1, 2, 3, 4, 5};
    display(array);
    reverse(array);
    display(array);
    return 0;
}