#include<iostream>
using namespace std;
int ** addMatrix(int ** &mat1,int ** &mat2,int m,int n){
    int ** res = new int*[m];
    for (int i = 0; i < m; i++){
        res[i] = new int[n];
    }
    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            res[i][j] = mat1[i][j] - mat2[i][j];
        }
    }
    return res;
    
}
void displayArray(int * &array,int size){
    for (int i = 0; i < size; i++){
        cout<<array[i]<<" ";
    }
    cout<<endl;
    return;
}
void displayMatrix(int ** &mat,int m, int n){
    for (int i = 0; i < m; i++){
        displayArray(mat[i],n);
    }
    
}
int main(){
    int m =3;
    int n =3;
    int mat1[m][n] = {
        {10,20,30},
        {40,50,60},
        {70,80,90}
    };
    int mat2[m][n] = {
        {5,5,5},
        {5,5,5},
        {5,5,5}
    };
    //--------------------------
    int ** mp1 = new int*[m];
    int ** mp2 = new int*[m];
    for (int i = 0; i < m; i++){
        mp1[i] = new int[n];
        mp2[i] = new int[n];
    }
    //-------------------------
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            mp1[i][j] = mat1[i][j];
            mp2[i][j] = mat2[i][j];
        }
    }
    // displayMatrix(mp1,m,n);
    // displayMatrix(mp2,m,n);
    //-------------------------
    int ** res = addMatrix(mp1,mp2,m,n);
    displayMatrix(res,m,n);
    return 0;
}