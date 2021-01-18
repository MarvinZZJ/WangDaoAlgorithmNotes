/*
例题6.11	计算两个矩阵的乘积（哈尔滨工业大学复试上机题）	
http://t.cn/Aip450PJ
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100;

struct Matrix{
    int row, col;
    int matrix[MAXN][MAXN];
    Matrix(){}
    Matrix(int r, int c): row(r), col(c){}
};

void InitialMatrix(Matrix &m){
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            cin >> m.matrix[i][j];
        }
    }
    return;
}

void PrintMatrix(Matrix m){
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            cout << m.matrix[i][j] << ' ';
        }
        cout << endl;
    }
    return;
}

Matrix Multipy(Matrix x, Matrix y){
    Matrix answer(x.row, y.col);
    for(int i = 0; i < x.row; i++){
        for(int j = 0; j < y.col; j++){
            for(int k = 0; k < x.col; k++){
                answer.matrix[i][j] += (x.matrix[i][k] * y.matrix[k][j]);
            }
        }
    }
    return answer;
}

int main(){
    Matrix x(2, 3);
    Matrix y(3, 2);
    InitialMatrix(x);
    InitialMatrix(y);
    Matrix answer = Multipy(x, y);
    PrintMatrix(answer);
    return 0;
}
