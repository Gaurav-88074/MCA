#include<iostream>
using namespace std;
void displayLine(int x){
    for (int i = 0; i <x; i++){
        cout<<"*";
    }
    cout<<endl;
}
void displaySpace(int x){
    for (int i = 0; i <x; i++){
        cout<<" ";
    }
}
void displayPattern(int n){
    for (int i = 0; i <n; i++){
        displaySpace((n-i));
        displayLine(max(1,i*3));
    }
    
}
int main(){
    displayPattern(4);
    return 0;
}