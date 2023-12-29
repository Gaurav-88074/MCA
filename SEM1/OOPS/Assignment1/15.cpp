#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
vector<string> split(string &s,char d){
    vector<string> res;
    string temp;
    for(int c:s){
        if(c==d){
            res.push_back(temp);
            temp="";
        }
        else{
            temp+=c;
        }
    }
    res.push_back(temp);
    return res;
}
void display(vector<string> v){
    for (string s:v ){
        cout<<s<<" ";
    }
    cout<<endl;
}
int main(){
    fstream obj("table.csv");
    string str;

    if(obj.is_open()){
        while (getline(obj,str)){
            vector<string> line = split(str,',');
            display(line);
        }
        obj.close();
    }
    
    return 0;
}