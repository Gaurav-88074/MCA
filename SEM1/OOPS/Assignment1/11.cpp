#include<iostream>
#include<vector>
using namespace std;

vector<int> operator*(vector<int> &obj,int x){
    vector<int> res;
    for(int i:obj){
        res.push_back(x*i);
    }
    return res;
}
vector<int> operator<<(vector<int> &obj,int x){
    vector<int> res;
    for(int i:obj){
        res.push_back(i<<x);
    }
    return res;
}
vector<int> operator>>(vector<int> &obj,int x){
    vector<int> res;
    for(int i:obj){
        res.push_back(i>>x);
    }
    return res;
}
void display(vector<int> &obj){
    cout<<"Displaying Your Array : ";
    for (int i:obj){
        cout<<i<<" ";
    }
    cout<<endl;
    
}
int main(){
    vector<int> vect1 = {10,20};

    vector<int> res1 =  vect1 * 7;
    vector<int> res2 =  vect1<<1;
    vector<int> res3 =  vect1>>1;

    display(res1);
    display(res2);
    display(res3);

    return 0;
}