/*
例题12.8	Piggy-Bank	
http://acm.hdu.edu.cn/showproblem.php?pid=1114
*/



// 法一：利用二维数组实现动态规划
#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 10001;
const int INF = INT_MAX / 10;

// w和v中下标0弃用
int w[MAXN];  // 物品的重量
int v[MAXN];  // 物品的价值
int dp[MAXN][MAXN];  // dp[i][j]表示前i个物品恰好装满j的背包，获得的最小价值为多少。（若无方案则为INF）

int main()
{
    int caseNum;
    cin >> caseNum;
    int e, f, m;  // e为陶猪的净重，f为硬币和空罐的总重量，m为银币总重量（背包容量）
    while(caseNum--){
        cin >> e >> f;
        m = f - e;
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++){
            cin >> v[i] >> w[i];
        }
        // 初始化边界
        for(int i = 0; i <= m; i++){
            if(i == 0){
                dp[0][0] = 0;
            }
            else{
                dp[0][i] = INF;  // 无方案
            }
        }
        for(int i = 0; i <= n; i++){
            dp[i][0] = 0;
        }
        // 求dp[][]
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                dp[i][j] = min(dp[i - 1][j], dp[i][j - w[i]] + v[i]);
            }
        }
        // 输出
        if(dp[n][m] == INF){
            cout << "This is impossible." << endl;
        }
        else{
            cout << "The minimum amount of money in the piggy-bank is " << dp[n][m] << "." << endl;
        }
    }
    return 0;
}





// 法二：利用一维数组实现动态规划
#include <iostream>
#include <cstdio>
#include <climits>

using namespace std;

const int MAXN = 10001;
const int INF = INT_MAX / 10;

int w[MAXN];  // 物品的重量
int v[MAXN];  // 物品的价值
int dp[MAXN];  // dp[j]表示前i个物品恰好装满j的背包，获得的最小价值为多少。（若无方案则为INF）

int main()
{
    int caseNum;
    cin >> caseNum;
    int e, f, m;  // e为陶猪的净重，f为硬币和空罐的总重量，m为银币总重量（背包容量）
    while(caseNum--){
        cin >> e >> f;
        m = f - e;
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> v[i] >> w[i];
        }
        // 初始化(当有0个物品供选择时)
        for(int i = 0; i <= m; i++){
            if(i == 0){
                dp[0] = 0;
            }
            else{
                dp[i] = INF;  // 无方案
            }
        }
        // 求当有n个物品可供选择时，恰好装满j的背包时，所得的dp[j]
        for(int i = 0; i < n; i++){
            for(int j = w[i]; j <= m; j++){
                dp[j] = min(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        // 输出
        if(dp[m] == INF){
            cout << "This is impossible." << endl;
        }
        else{
            cout << "The minimum amount of money in the piggy-bank is " << dp[m] << "." << endl;
        }
    }
    return 0;
}
