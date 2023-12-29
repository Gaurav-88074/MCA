#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int main(){
    fstream obj("data.txt");
    string line;
    char chr;
    int lines = 0;
    int words = 0;
    int chars = 0;
    if(obj.is_open()){
        while (obj.get(chr)){
            if(chr=='\n'){
                lines+=1;
                words+=1;
            }
            else if(chr==' '){
                words+=1;
            }
            else{
                chars+=1;
            }
        }
        obj.close();
    }
    cout<<"Words : "<<words<<endl;
    cout<<"Lines : "<<lines<<endl;
    cout<<"chars : "<<chars<<endl;
    
    return 0;
}