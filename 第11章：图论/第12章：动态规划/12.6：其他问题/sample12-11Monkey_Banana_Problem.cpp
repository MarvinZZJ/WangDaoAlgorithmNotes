/*
例题12.11	Monkey Banana Problem	
http://lightoj.com/volume_showproblem.php?problem=1004
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;

int matrix[MAXN * 2][MAXN];
int dp[MAXN * 2][MAXN];

int main(){
    int caseNum = 0;
    cin >> caseNum;
    for(int cas = 1; cas <= caseNum; cas++){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= i; j++){
                cin >> matrix[i][j];
                dp[i][j] = matrix[i][j];
            }
        }
        for(int i = n + 1; i <= 2 * n - 1; i++){
            for(int j = 1; j <= 2 * n - i; j++){
                cin >> matrix[i][j];
                dp[i][j] = matrix[i][j];
            }
        }
        for(int i = 2 * (n - 1); i >= n; i--){
            for(int j = 1; j <= 2 * n - i; j++){
                if(j == 1){
                    dp[i][j] += dp[i + 1][j];
                }
                else if(j == 2 * n - i){
                    dp[i][j] += dp[i + 1][j - 1];
                }
                else{
                    dp[i][j] += max(dp[i + 1][ j - 1], dp[i + 1][j]);
                }
            }
        }
        for(int i = n - 1; i >= 1; i--){
            for(int j = 1; j <= i; j++){
                dp[i][j] += max(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        cout << "Case " << cas << ": " << dp[1][1] << endl;
    }
    return 0;
}
