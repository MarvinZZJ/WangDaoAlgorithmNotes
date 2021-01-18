/*
例题6.12	矩阵幂（北京邮电大学复试上机题）	
http://t.cn/Aip4T3HX
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10 + 1;

struct Matrix{
    int matrix[MAXN][MAXN];
    int row, col;
    Matrix(){}
    Matrix(int r, int c): row(r), col(c){}
};

void InputMatrix(Matrix &m){
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            cin >> m.matrix[i][j];
        }
    }
    return;
}

Matrix Multiply(Matrix x, Matrix y){
    Matrix answer(x.row, y.col);
    for(int i = 0; i < x.row; i++){
        for(int j = 0; j < y.col; j++){
            int current = 0;
            for(int k = 0; k < x.col; k++){
                current += (x.matrix[i][k] * y.matrix[k][j]);
            }
            answer.matrix[i][j] = current;
        }
    }
    return answer;
}

void PrintMatrix(Matrix m){
    for(int i = 0; i < m.row; i++){
        for(int j = 0; j < m.col; j++){
            if(j != 0){
                cout << ' ';
            }
            cout << m.matrix[i][j];
        }
        cout << endl;
    }
    return;
}

Matrix FastExponentiation(Matrix m, int k){
    Matrix answer(m.row, m.col);
    for(int i = 0; i < answer.row; i++){
        for(int j = 0; j < answer.col; j++){
            if(i == j){
                answer.matrix[i][j] = 1;
            }
            else{
                answer.matrix[i][j] = 0;
            }
        }
    }
    while(k != 0){
        if(k % 2 == 1){
            answer = Multiply(answer, m);
        }
        k /= 2;
        m = Multiply(m, m);
    }
    return answer;
}

int main(){
    int caseNum;
    cin >> caseNum;
    int n, k;
    while(caseNum--){
        cin >> n >> k;
        Matrix m(n, n);
        InputMatrix(m);
        m = FastExponentiation(m, k);
        PrintMatrix(m);
    }
    return 0;
}
