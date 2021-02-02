/*
例题12.4	拦截导弹（北京大学复试上机题）	
http://t.cn/AiYCeV3m
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25 + 5;

int height[MAXN];  // 按时间顺序存储每个导弹的飞行高度

int dp[MAXN];  // dp[i] 表示导弹i作为最后一个拦截的导弹时，一共拦截最多导弹数为dp[i]


int GetMaxDescendSubsequence(int n){
    int answer = 0;
    for(int i = 0; i < n; i++){
        dp[i] = 1;  // 初始值表示只拦截了当前i这一个导弹
        // 遍历导弹i前面的各个导弹j的高度，如果出现≥导弹i高度的导弹，则进行判断。
        for(int j = 0; j < i; j++){
            if(height[j] >= height[i]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        answer = max(answer, dp[i]);
    }
    return answer;
}

int main()
{
    int k;
    while(cin >> k){
        for(int i = 0; i < k; i++){
            cin >> height[i];
        }
        int answer = GetMaxDescendSubsequence(k);
        cout << answer << endl;
    }
    return 0;
}
