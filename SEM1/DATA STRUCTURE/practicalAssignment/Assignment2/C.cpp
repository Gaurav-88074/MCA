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
vector<vector<int>> add(vector<vector<int>> &mat1,vector<vector<int>> mat2){
    int m = mat1.size();
    int n = mat1[0].size();
    vector<vector<int>> res(m,vector<int>(n));
    for(int i = 0;i<m ; i++){
        for (int j = 0; j < n; j++){
            res[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    return res;
}
int main(){
    int m = 2;
    int n = 2;
    vector<vector<int>> mat1(m,vector<int>(n));
    mat1[0][0] = 5;
    mat1[0][1] = 5;
    mat1[1][0] = 5;
    mat1[1][1] = 5;
    vector<vector<int>> mat2(m,vector<int>(n));
    mat2[0][0] = 5;
    mat2[0][1] = 5;
    mat2[1][0] = 5;
    mat2[1][1] = 5;
    display(mat1);
    display(mat2);
    vector<vector<int>> res = add(mat1,mat2);
    display(res);
    return 0;
}