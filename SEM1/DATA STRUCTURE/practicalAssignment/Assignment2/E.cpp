#include<iostream>
#include<vector>
using namespace std;
void display(vector<vector<int>> mat){
    cout<<"Displaying Your Matrix : "<<endl;
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0;i<m ; i++){
        for (int j = 0; j < n; j++){
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}

int main(){
    int m = 2;
    int n = 2;
    vector<vector<int>> mat1(m,vector<int>(n));
    mat1[0][0] = 5;
    mat1[0][1] = 6;
    mat1[1][0] = 7;
    mat1[1][1] = 8;
    display(mat1);
    return 0;
}