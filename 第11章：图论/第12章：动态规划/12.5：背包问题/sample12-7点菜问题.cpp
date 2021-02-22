/*
例题12.7	点菜问题（北京大学复试上机题）	
http://t.cn/AiYOrkXr
*/




// 法一：使用二维数组进行动态规划（未优化）
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int MAXW = 1001;

// 下标0在dp中作为边界条件，在w和v中弃用
int w[MAXN];  // 物品重量（菜品售价）
int v[MAXN];  // 物品价值（菜品美味系数）

int dp[MAXN][MAXW];  // dp[i][j]代表前i个物品存放在容量为j的背包中能获得的最大价值


int main()
{
    int c, n;
    while(cin >> c >> n){
        // 初始化
        memset(dp, 0, sizeof(dp));
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        // 输入w[]和v[]
        for(int i = 1; i <= n; i++){
            cin >> w[i] >> v[i];
        }
        // 创建dp[][]
        for(int i = 1; i <= n; i++){  // (边界)i = 0时，必有dp[0][j]=0
            for(int j = w[i]; j <= c; j++){  // 背包容量小于w[i]时，必有dp[i][j]=0
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
        cout << dp[n][c] << endl;
    }
    return 0;
}





// 法二：可以将二维dp数组优化为一个一维dp数组
//       因为每个dp[i][*]只与dp[i - 1][*]保存的数据有关，而与前面的dp[i - 2][*]等无关
//       因此dp数组中的元素可以逐层覆盖掉（但要从右往左更新）
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXN = 101;
const int MAXW = 1001;

// 下标0在w和v中弃用
int w[MAXN];  // 物品重量（菜品售价）
int v[MAXN];  // 物品价值（菜品美味系数）

int dp[MAXW];  // dp[j]代表前i个物品存放在容量为j的背包中能获得的最大价值


int main()
{
    int c, n;
    while(cin >> c >> n){
        // 初始化
        memset(dp, 0, sizeof(dp));  // 代表有0个物品时，必有dp[*] = 0
        memset(w, 0, sizeof(w));
        memset(v, 0, sizeof(v));
        // 输入w[]和v[]
        for(int i = 1; i <= n; i++){
            cin >> w[i] >> v[i];
        }
        // 创建dp[]最终表示有i个物品选择时的dp
        for(int i = 1; i <= n; i++){
            for(int j = c; j >= w[i]; j--){  // 背包容量小于w[i]时，必有dp[i][j]=0
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[c] << endl;
    }
    return 0;
}
