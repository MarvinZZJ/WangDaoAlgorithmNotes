/*
习题6.11	递推数列（清华大学复试上机题）	
http://t.cn/AipbZ2sS
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;

struct Matrix{
    int row, col;
    int matrix[MAXN][MAXN];
    Matrix(){}
    Matrix(int r, int c): row(r), col(c){}
};

Matrix Multiply(Matrix x, Matrix y, int mod){
    Matrix answer(x.row, y.col);
    for(int i = 0; i < x.row; i++){
        for(int j = 0; j < y.col; j++){
            int current = 0;
            for(int k = 0; k < x.col; k++){
                current += (x.matrix[i][k] * y.matrix[k][j] % mod);
                current %= mod;
            }
            answer.matrix[i][j] = current;
        }
    }
    return answer;
}

Matrix FastExponentiation(Matrix m, int k, int mod){
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
            answer = Multiply(answer, m, mod);
        }
        k /= 2;
        m = Multiply(m, m, mod);
    }
    return answer;
}


int main(){
    int a0, a1, p, q, k;
    while(cin >> a0 >> a1 >> p >> q >> k){
        Matrix x(2, 2);
        x.matrix[0][0] = p;
        x.matrix[0][1] = q;
        x.matrix[1][0] = 1;
        x.matrix[1][1] = 0;
        Matrix res(2, 2);
        res = FastExponentiation(x, k - 1, 1e4);
        int answer = (res.matrix[0][0] * a1 + res.matrix[0][1] * a0) % 10000;
        cout << answer << endl;
    }
    return 0;
}
