/*
附加题12.2 湫湫系列故事——减肥记I
http://acm.hdu.edu.cn/showproblem.php?pid=4508
*/

// 法一：利用二维数组实现动态规划
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 10;

int value[MAXN];
int calorie[MAXN];

int dp[MAXN][MAXM];

int main()
{
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> value[i] >> calorie[i];
        }
        int m;
        cin >> m;
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= m; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(calorie[i] > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - calorie[i]] + value[i]);
                }
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}





// 法二：利用一维数组实现动态规划

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e2 + 10;
const int MAXM = 1e5 + 10;

int value[MAXN];
int calorie[MAXN];

int dp[MAXM];

int main()
{
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> value[i] >> calorie[i];
        }
        int m;
        cin >> m;
        for(int i = 0; i <= m; i++){
            dp[i] = 0;
        }
        for(int i = 1; i <= n; i++){
            for(int j = calorie[i]; j <= m; j++){
                dp[j] = max(dp[j], dp[j - calorie[i]] + value[i]);
            }
        }
        cout << dp[m] << endl;
    }
    return 0;
}
