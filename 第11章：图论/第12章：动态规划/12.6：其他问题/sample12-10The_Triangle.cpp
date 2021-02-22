/*
例题12.10	The Triangle	
http://poj.org/problem?id=1163
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 101;

int matrix[MAXN][MAXN];  // 存储输入的上三角矩阵

int dp[MAXN][MAXN];  // dp[i][j]表示存储从(i,j)点出发到底部路径所有值之和的最大值


int main()
{
    int r;
    while(cin >> r){
        // 输入矩阵值
        for(int i = 0; i < r; i++){
            for(int j = 0; j <= i; j++){
                cin >> matrix[i][j];
            }
        }
        // 初始化边界条件
        for(int i = 0; i < r; i++){
            dp[r - 1][i] = matrix[r - 1][i];
        }
        // 求dp[]
        for(int i = r - 2; i >= 0; i--){
            for(int j = 0; j <= r; j++){
                dp[i][j] = max(dp[i + 1][j], dp[i + 1][j + 1]) + matrix[i][j];
            }
        }
        // 输出dp[0][0]即为所求
        cout << dp[0][0] << endl;
    }
    return 0;
}
