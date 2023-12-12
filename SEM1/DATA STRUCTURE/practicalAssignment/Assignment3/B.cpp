#include<iostream>
using namespace std;
void displayLine(){
    cout<<"#######"<<endl;
}
void displaySpace(){
    cout<<"#     #"<<endl;
}
void displayPattern(int n){
    displayLine();
    for (int i = 0; i < n; i++){
        displaySpace();
    }
    displayLine();
    
}
int main(){
    displayPattern(5);
    return 0;
}