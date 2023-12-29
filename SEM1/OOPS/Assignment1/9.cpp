#include<iostream>
using namespace std;
class Matrix{
    private:
        int row;
        int col;
        int** mat;
    public:
        Matrix(int row,int col){
            this->row = row;
            this->col = col;
            this->mat = new int*[row];
            for (int i = 0; i < col; i++){
                this->mat[i] = new int[col];
            }
            
        }
        void insert(int i,int j,int value){
            this->mat[i][j] = value;
        }
        int retrive(int i,int j){
            return this->mat[i][j];
        }
};
int main(){
    Matrix obj(2,2);

    obj.insert(0,0,10);
    obj.insert(0,1,20);
    obj.insert(1,0,30);
    obj.insert(1,1,40);
    
    cout<<obj.retrive(1,1);
    return 0;
}