#include<iostream>
using namespace std;
void transpose(int ** &mat,int m,int n){
    for (int i = 0; i < m; i++){
        for (int j = 0; j < i; j++){
            int val   = mat[i][j];
            mat[i][j] = mat[j][i];
            mat[j][i] = val;
        }
    }    
}
void displayArray(int * &array,int size){
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return;
}
void displayMatrix(int ** &mat,int m, int n){
    cout<<"Displaying your matrix..."<<endl;
    for (int i = 0; i < m; i++){
        displayArray(mat[i],n);
    }
    
}
int main(){
    int m =3;
    int n =3;
    int mat[m][n] = {
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };
    //--------------------------
    int ** mp = new int*[m];
    for (int i = 0; i < m; i++){
        mp[i] = new int[n];
    }
    //-------------------------
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            mp[i][j] = mat[i][j];
        }
    }
    displayMatrix(mp,m,n);
    transpose(mp,m,n);
    displayMatrix(mp,m,n);
    //-------------------------
    // int ** res = addMatrix(mp1,mp2,m,n);
    // displayMatrix(res,m,n);
    return 0;
}