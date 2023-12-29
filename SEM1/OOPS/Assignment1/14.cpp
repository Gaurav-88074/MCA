#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    fstream obj("data.txt");

    string str;
    string target="DUCS-MCA";

    char chr;
    int lines = 0;
    if(obj.is_open()){
        while (obj.get(chr)){
            if(chr=='\n' || chr==' '){
                if(str==target){
                    cout<<"String Found at line no. "<<lines+1<<endl;
                }
                str="";
            }
            else{
                str += chr;
            }
            lines+=(chr=='\n');
        }
        obj.close();
    }
    
    return 0;
}