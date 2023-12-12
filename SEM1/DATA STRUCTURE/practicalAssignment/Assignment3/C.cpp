#include<iostream>
using namespace std;
void displayLine(int x){
    for(int i = 0 ; i<x;i++){
        cout<<x<<"";
    }
    cout<<endl;
}
void displayPattern(int n){
    for (int i = 1; i <=n; i++){
        displayLine(i);
    }    
}
int main(){
    displayPattern(5);
    return 0;
}