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
void transpose(vector<vector<int>> &mat){
    int m = mat.size();
    int n = mat[0].size();
    for(int i = 0;i<m ; i++){
        for (int j = 0; j <i; j++){
            swap(mat[i][j],mat[j][i]);
        }
    }
}
int main(){
    int m = 2;
    int n = 2;
    vector<vector<int>> mat(m,vector<int>(n));
    mat[0][0] = 5;
    mat[0][1] = 6;
    mat[1][0] = 7;
    mat[1][1] = 8;
    display(mat);
    transpose(mat);
    display(mat);
    return 0;
}
