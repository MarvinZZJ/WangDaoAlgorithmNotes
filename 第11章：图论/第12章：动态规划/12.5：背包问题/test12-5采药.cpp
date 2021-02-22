/*
习题12.5	采药（北京大学复试上机题）
https://www.nowcoder.com/practice/d7c03b114f0541dd8e32ce9987326c16?tpId=61&tqId=29547&tPage=3&ru=%2Fkaoyan%2Fretest%2F1002&qru=%2Fta%2Fpku-kaoyan%2Fquestion-ranking
*/


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXT = 1001;
const int MAXM = 101;

int w[MAXM];  // 采该草药所需时间，草药编号1~MAXM
int v[MAXM];  // 该草药的价值，草药编号1~MAXM

int dp[MAXT];  // dp[j]表示有i株草药、有j时间可以采得的草药的最大价值

int main()
{
    int t, m;
    while(cin >> t >> m){
        for(int i = 1; i <= m; i++){
            cin >> w[i] >> v[i];
        }
        // 初始化dp，即可选草药数为0，提供时间为j，所采的草药的最大价值必为dp[j] = 0
        for(int i = 0; i <= t; i++){
            dp[i] = 0;
        }
        // 求可选草药数为m，提供时间为j时，可以获得的最大价值dp[j]
        for(int i = 1; i <= m; i++){
            for(int j = t; j >= w[i]; j--){
                dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
            }
        }
        cout << dp[t] << endl;
    }
    return 0;
}
