/*
例题8.3	Fibonacci（上海交通大学复试上机题）	
http://t.cn/Ai0K3tU5
*/

// 法1：分治法O(2^n)  最低效的方法
#include <iostream>
#include <cstdio>

using namespace std;

int Fibonacci(int n){
    if(n == 0 || n == 1){
        return n;
    }
    else{
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << Fibonacci(n) << endl;
    }
    return 0;
}




// 法2：递推法O(n)
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 31;
int Fibonacci[MAXN];

void InitialFibonacci(){
    Fibonacci[0] = 0;
    Fibonacci[1] = 1;
    for(int i = 2; i < MAXN; i++){
        Fibonacci[i] = Fibonacci[i - 1] + Fibonacci[i - 2];
    }
}

int main(){
    int n;
    InitialFibonacci();
    while(cin >> n){
        cout << Fibonacci[n] << endl;
    }
}




// 法3：矩阵快速幂法 O(logn)
// {  f(k) }      { 1       1 } {   f(k-1)  }     { 1       1 }^(k-1) {   f1  }
// {       }   =  {           }*{           }  =  {           }   *   {       }
// { f(k-1)}      { 1       0 } {   f(k-2)  }     { 1       0 }       {   f0  }
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;

struct Matrix{
    int matrix[MAXN][MAXN];
    int row, col;
    Matrix(){}
    Matrix(int r, int c): row(r), col(c){}
};

Matrix Multiply(Matrix x, Matrix y){
    Matrix answer(x.row, y.col);
    for(int i = 0; i < answer.row; i++){
        for(int j = 0; j < answer.col; j++){
            answer.matrix[i][j] = 0;
        }
    }
    for(int i = 0; i < x.row; i++){
        for(int j = 0; j < y.col; j++){
            for(int k = 0; k < x.col; k++){
                answer.matrix[i][j] += (x.matrix[i][k] * y.matrix[k][j]);
            }
        }
    }
    return answer;
}

Matrix FastExponentiation(Matrix x, int k){
    Matrix answer(x.row, x.col);
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
        if(k % 2 != 0){
            answer = Multiply(answer, x);
        }
        k /= 2;
        x = Multiply(x, x);
    }
    return answer;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0 || n == 1){
            cout << n << endl;
            continue;
        }
        Matrix fibonacci(2, 2);
        fibonacci.matrix[0][0] = 1;
        fibonacci.matrix[0][1] = 1;
        fibonacci.matrix[1][0] = 1;
        fibonacci.matrix[1][1] = 0;
        Matrix answer = FastExponentiation(fibonacci, n - 1);
        cout << 1 * answer.matrix[0][0] + 0 * answer.matrix[0][1] << endl;
    }
    return 0;
}
