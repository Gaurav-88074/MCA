#include<iostream>
using namespace std;

void displayPattern(int n){
    for (int i = 1; i <= n; i += 2) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }
    for (int i = n - 2; i >= 1; i -= 2) {
        for (int j = 0; j < i; ++j) {
            cout << "*";
        }
        cout << endl;
    }  
}
int main(){
    displayPattern(5);
    return 0;
}