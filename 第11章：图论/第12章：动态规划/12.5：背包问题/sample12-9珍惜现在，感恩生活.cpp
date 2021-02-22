/*
例题12.9	珍惜现在，感恩生活	
http://acm.hdu.edu.cn/showproblem.php?pid=2191
*/

// 方法一：利用二维数组实现动态规划
#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int MAX = 100 + 10;

int price[MAX];
int weight[MAX];
int number[MAX];

int newPrice[MAX * 20];
int newWeight[MAX * 20];

int dp[MAX * 20][MAX];

int main(){
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        int n, m;
        cin >> m >> n;
        for(int i = 1; i <= n; i++){
            cin >> price[i] >> weight[i] >> number[i];
        }
        int num = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= number[i] ; j *= 2){
                num++;
                newPrice[num] = price[i] * j;
                newWeight[num] = weight[i] * j;
                number[i] -= j;
            }
            if(number[i] != 0){
                num++;
                newPrice[num] = price[i] * number[i];
                newWeight[num] = weight[i] * number[i];
            }
        }
        for(int i = 0; i <= num; i++){
            dp[i][0] = 0;
        }
        for(int i = 0; i <= m; i++){
            dp[0][i] = 0;
        }
        for(int i = 1; i <= num; i++){
            for(int j = 1; j <= m; j++){
                if(newPrice[i] > j){
                    dp[i][j] = dp[i - 1][j];
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - newPrice[i]] + newWeight[i]);
                }
            }
        }
        cout << dp[num][m] << endl;
    }
    return 0;
}




// 方法二：利用一维数组实现动态规划
#include <iostream>
#include <cstdio>

using namespace std;

// 大米种类-->物品
// 大米价格-->物品重量
// 大米质量-->物品价值
// 资金-->背包容量

const int MAXN = 10000;

int w[MAXN];  // 物品重量
int v[MAXN];  // 物品价值
int k[MAXN];  //物品数量
int value[MAXN];  // 分解后的物品价值
int weight[MAXN];  // 分解后的物品重量
int dp[MAXN];
int main()
{
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        int n, m;  // n种物品，背包容量m
        cin >> m >> n;
        int number = 0;  // 存放分解后的物品数量
        for(int i = 0; i < n; i++){
            cin >> w[i] >> v[i] >> k[i];
            //构造分解后的value和weight
            for(int j = 1; j <= k[i]; j *= 2){
                value[number] = j * v[i];
                weight[number] = j * w[i];
                number++;
                k[i] -= j;  // 减去该组合使用的该类物品的个数j
            }
            if(k[i] > 0){
                value[number] = k[i] * v[i];
                weight[number] = k[i] * w[i];
                number++;
            }
        }
        // 利用0-1背包思想求解dp[]
        // 1.初始化dp[]
        for(int i = 0; i <= m; i++){
            dp[i] = 0;
        }
        // 2.求有number个物品时的dp[]
        for(int i = 0; i < number; i++){
            for(int j = m; j >= weight[i]; j--){
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
            }
        }
        // 输出
        cout << dp[m] << endl;
    }
    return 0;
}
