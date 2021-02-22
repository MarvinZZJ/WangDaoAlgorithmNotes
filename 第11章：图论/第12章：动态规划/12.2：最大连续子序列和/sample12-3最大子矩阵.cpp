/*
例题12.3	最大子矩阵（北京大学复试上机题）	
http://t.cn/AiYSemJz
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <climits>

using namespace std;

const int MAXN = 100 + 10;

const int INF = INT_MAX;

int matrix[MAXN][MAXN];

int totalAdd[MAXN][MAXN];  // totalAdd[i][k],记录第0~i行、第k列数据的总和

int arr[MAXN];

int dp[MAXN];  // 存放以arr[i]为结尾的arr的最大子序列和

int MaxSubsequence(int n){
    int maximal;
    memset(dp, -INF, sizeof(dp));
    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i] = arr[i];
            maximal = dp[i];
        }
        else{
            dp[i] = max(dp[i - 1] + arr[i], arr[i]);
        }
        maximal = max(maximal, dp[i]);
    }
    return maximal;
}

int MaxSubmatrix(int n){
    int maximum = -128;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            // 更新arr数组的值
            for(int k = 0; k < n; k++){
                if(i == 0){
                    arr[k] = totalAdd[j][k];
                }
                else{
                    arr[k] = totalAdd[j][k] - totalAdd[i - 1][k];
                }
            }
            int currentMax = MaxSubsequence(n);
            maximum = max(maximum, currentMax);
        }
    }
    return maximum;
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> matrix[i][j];
            }
        }
        memset(totalAdd, 0, sizeof(totalAdd));
        // 创建totalAdd
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(i == 0){
                    totalAdd[i][j] = matrix[i][j];
                }
                else{
                    totalAdd[i][j] = matrix[i][j] + totalAdd[i - 1][j];
                }
            }
        }
        // 获取最大子矩阵和
        int answer = MaxSubmatrix(n);
        cout << answer << endl;
    }
    return 0;
}
