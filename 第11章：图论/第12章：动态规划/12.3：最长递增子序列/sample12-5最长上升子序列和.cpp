/*
例题12.5	最长上升子序列和（北京大学复试上机题）	
http://t.cn/AiYNAGD3
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int arr[MAXN];

int dp[MAXN];  // 存放以arri[i]作为序列末尾的最大上升子序列和

int GetMaxAscendSubsequence(int n){
    int answer = 0;
    for(int i = 0; i < n; i++){
        dp[i] = arr[i];  // 初始化为该子序列只有arr[i]这一元素
        // 判断前面的最大上升子序列末尾元素是否有比arr[i]小
        for(int j = 0; j < i; j++){
            if(arr[j] < arr[i]){
                dp[i] = max(dp[i], dp[j] + arr[i]);
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
            cin >> arr[i];
        }
        cout << GetMaxAscendSubsequence(k) << endl;
    }
    return 0;
}
