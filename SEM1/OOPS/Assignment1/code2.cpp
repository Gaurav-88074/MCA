#include<iostream>
#include<fstream>
using namespace std;
int countLines(string &s){
    int res  = 0;
    for(char c : s){
        if(c==' '){
            res+=1;
        }
    }
    if(s.length()>0){
        return res+1;
    }
    return res;
}
int main(){
    fstream obj("data.txt");
    string line;
    char chr;
    string s;
    int lines = 0;
    int words = 0;
    int chars = 0;
    if(obj.is_open()){
        while (getline(obj,s)){
            // cout<<s<<endl;
            int v = countLines(s);
            words+=v;
            lines+=1;
        }
        obj.close();
    }
    cout<<"Words : "<<words<<endl;
    cout<<"Lines : "<<lines<<endl;
    // cout<<"chars : "<<chars<<endl;
    
    return 0;
}