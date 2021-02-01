/*
习题12.2	最大连续子序列（浙江大学复试上机题）	
http://t.cn/AiYoUkjP
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e4 + 10;

int arr[MAXN];

// 用于存放以该点为终点的最大子串和
struct EndPos{
    int maxSub;
    int from;  // 起始点坐标
    int to;  // 终点坐标
    EndPos(){}
    EndPos(int m, int f, int t): maxSub(m), from(f), to(t){}
};

EndPos dp[MAXN];

EndPos MaxSubsequence(int n){
    EndPos answer;
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dp[i].maxSub = arr[i];
            dp[i].from = i;
            dp[i].to = i;
            answer = dp[i];
        }
        else{
            if(dp[i - 1].maxSub + arr[i] >= arr[i]){
                dp[i].maxSub = dp[i - 1].maxSub + arr[i];
                dp[i].from = dp[i - 1].from;
                dp[i].to = i;
            }
            else{
                dp[i].maxSub = arr[i];
                dp[i].from = dp[i].to = i;
            }
        }
        if(answer.maxSub < dp[i].maxSub){
            answer = dp[i];
        }
    }
    return answer;
}

int main(){
    int k;
    while(cin >> k){
        if(k == 0){
            break;
        }
        for(int i = 1; i <= k; i++){
            cin >> arr[i];
        }
        EndPos answer = MaxSubsequence(k);
        if(answer.maxSub < 0){
            printf("0 %d %d\n", arr[1], arr[k]);
        }
        else{
            printf("%d %d %d\n",answer.maxSub, arr[answer.from], arr[answer.to]);
        }
    }
    return 0;
}
