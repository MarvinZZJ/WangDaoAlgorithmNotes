/*
习题6.10	A+B for Matrices（浙江大学复试上机题）	
http://t.cn/Aipb7GBG
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAX = 10 + 1;

struct Matrix{
    int row, col;
    int matrix[MAX][MAX];
    Matrix(){}
    Matrix(int r, int c): row(r), col(c){}
};

void InputMatrixData(Matrix &m){
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            cin >> m.matrix[i][j];
        }
    }
    return;
}

Matrix Add(Matrix x, Matrix y){
    Matrix answer(x.row, x.col);
    for(int i = 0; i < x. row; i++){
        for(int j = 0; j < x.col; j++){
            answer.matrix[i][j] = x.matrix[i][j] + y.matrix[i][j];
        }
    }
    return answer;
}

int NumOfZeroLine(Matrix m){
    int res = 0;
    for(int i = 0; i < m.row; i++){
        bool flag = true;
        for(int j = 0; j < m.col; j++){
            if(m.matrix[i][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            res++;
        }
    }
    for(int i = 0; i < m.col; i++){
        bool flag = true;
        for(int j = 0; j < m.row; j++){
            if(m.matrix[j][i]){
                flag = false;
                break;
            }
        }
        if(flag){
            res++;
        }
    }
    return res;
}

int main(){
    int m, n;
    while(cin >> m){
        if(m == 0){
            break;
        }
        cin >> n;
        Matrix x(m, n);
        Matrix y(m, n);
        InputMatrixData(x);
        InputMatrixData(y);
        Matrix answer(m, n);
        answer = Add(x, y);
        cout << NumOfZeroLine(answer) << endl;
    }
    return 0;
}
