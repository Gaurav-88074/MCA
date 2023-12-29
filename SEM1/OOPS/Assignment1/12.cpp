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
        void display(){
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    cout<<this->retrive(i,j)<<" ";
                }
                cout<<endl;
            }
        }

        Matrix operator+(Matrix &that){
            if(this->row!=that.row){
                cout<<"Dimension Error!!"<<endl;
                return Matrix(0,0);
            }
            if(this->col!=that.col){
                cout<<"Dimension Error!!"<<endl;
                return Matrix(0,0);
            }
            Matrix res(this->row,this->col);
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    res.insert(i,j,this->retrive(i,j)+that.retrive(i,j));
                }
            }
            return res;
        }
        Matrix operator*(Matrix &that){
            if(this->col!=that.row){
                cout<<"Dimension Error!!"<<endl;
                return Matrix(0,0);
            }
            Matrix res(this->row,this->col);
            for (int i = 0; i < this->row; i++){
                for (int j = 0; j < this->col; j++){
                    int value = 0;
                    for (int k = 0; k < this->col; k++){
                        value+=mat[i][k]*that.mat[k][j];
                    }
                    res.insert(i,j,value);
                }
            }
            return res;
        }
};

int main(){
    Matrix obj1(2,2);
    Matrix obj2(2,2);

    obj1.insert(0,0,1);
    obj1.insert(0,1,2);
    obj1.insert(1,0,3);
    obj1.insert(1,1,4);

    obj2.insert(0,0,1);
    obj2.insert(0,1,0);
    obj2.insert(1,0,0);
    obj2.insert(1,1,1);

    cout<<"Mat 1 : "<<endl;
    obj1.display();

    cout<<"Mat 2 : "<<endl;
    obj2.display();

    cout<<"After Performing Addition operation : "<<endl;
    Matrix obj3 = obj1+obj2;
    obj3.display();

    cout<<"After Performing Multiplication operation :"<<endl;
    Matrix obj4 = obj1*obj2;
    obj4.display();

    return 0;
}