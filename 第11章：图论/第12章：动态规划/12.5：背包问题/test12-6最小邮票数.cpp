/*
习题12.6	最小邮票数（清华大学复试上机题）	
http://t.cn/AiYlwchD
*/



// 方法一：动态规划

//0-1最小背包问题 求解装满背包的前提下使用物品最少的数量
//其中：
//    邮票总值相当于背包容量，
//    邮票的面值相当于物品的重量，
//    邮票的数量相当于物品的总价值，
//    每张邮票的价值默认为1。

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 20 + 10;
const int MAXM = 100 + 10;

int w[MAXN];  // 邮票的面值（物品的重量）

int dp[MAXM];  // dp[j]保存：在i张邮票中凑够j面值所需最少的邮票数

const int INF = 10000;

int main()
{
    int m, n;
    while(cin >> m >> n){
        for(int i = 1; i <= n; i++){
            cin >> w[i];
        }
        // 初始化
        for(int i = 0; i <= m; i++){
            if(i == 0){
                dp[i] = 0;  // 0张可选邮票凑够总面值为0，需要0张
            }
            else{
                dp[i] = INF;  // 0张可选邮票凑够总面值为i，无解(设为INF)
            }
        }
        for(int i = 1; i <= n; i++){
            int current = w[i];
            for(int j = m; j >= current; j--){
                dp[j] = min(dp[j], dp[j - current] + 1);
            }
        }
        int answer = (dp[m] == INF ? 0 : dp[m]);
        cout << answer << endl;
    }
    return 0;
}




// 法二：DFS
const int MAXN = 20;
const int INF = 1000;
int minNum;  //保存最小所需邮票数

int w[MAXN];  // 邮票面额


void DFS(int m, int nowW, int n, int nowPos, int nowNum){
    if(m == nowW){
        minNum = (minNum > nowNum ? nowNum : minNum);
    }
    else if(m < nowW || n == nowPos || minNum <= nowNum){
        // 剪枝
    }
    else{
        DFS(m, nowW, n, nowPos + 1, nowNum);  // 不选择邮票nowPos
        DFS(m, nowW + w[nowPos], n, nowPos + 1, nowNum + 1);  // 选择邮票nowPos
    }
    return ;
}

int main(){
    int m, n;
    while(cin >> m >> n){
        for(int i = 0; i < n; i++){
            cin >> w[i];
        }
        minNum = INF;
        DFS(m, 0, n, 0, 0);
        cout << (minNum == INF ? 0 : minNum) << endl;
    }
}
