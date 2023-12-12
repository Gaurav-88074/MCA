#include <iostream>
#include <vector>
using namespace std;
vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int top = 0;
    int right = col - 1;
    int bottom = row - 1;
    int left = 0;
    vector<int> spiralledArray;

    while (top <= bottom && left <= right)
    {
        for (int i = left; i <= right; i++)
        {
            spiralledArray.push_back(matrix[top][i]);
        }
        top++;

        for (int i = top; i <= bottom; i++)
        {
            spiralledArray.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            for (int i = right; i >= left; i--)
            {
                spiralledArray.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            for (int i = bottom; i >= top; i--)
            {
                spiralledArray.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return spiralledArray;
}
void displayVect(vector<int> &array){
    for(int i:array){
        cout<<i<<" ";
    }
    cout<<endl;
}
void display(vector<vector<int>> mat)
{
    cout << "Displaying Your Matrix : " << endl;
    int m = mat.size();
    int n = mat[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int m = 2;
    int n = 2;
    vector<vector<int>> mat1(m, vector<int>(n));
    mat1[0][0] = 5;
    mat1[0][1] = 6;
    mat1[1][0] = 7;
    mat1[1][1] = 8;
    display(mat1);
    vector<int> res = spiralOrder(mat1);
    displayVect(res);
    return 0;
}