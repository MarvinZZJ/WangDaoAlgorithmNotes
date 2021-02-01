/*
例题12.2	最大序列和（清华大学复试上机题）	
http://t.cn/AiYSlQMU
*/

// 法一：递推方式， 时间复杂度O(n)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

const int MAXN = 1e6 + 10;

long long arr[MAXN];

long long dp[MAXN];

const int INF = INT_MAX;

void MaxSubsequence(int n){
    long long maximum;
    for(int i = 0; i < n; i++){
        if(i == 0){
            dp[i] = arr[i];
        }
        else{
            dp[i] = max(arr[i], arr[i] + dp[i - 1]);
        }
    }
    return;
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        fill(dp, dp + n, -1);
        MaxSubsequence(n);
        long long answer = -INF;
        for(int i = 0; i < n; i++){
            answer = max(answer, dp[i]);
        }
        cout << answer << endl;
    }
    return 0;
}

// 法二：朴素递归,时间复杂度O(n^3)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

const int MAXN = 1e6 + 10;

long long arr[MAXN];

const int INF = INT_MAX;

long long MaxSubsequence2(int n){
    long long maximum;
    if(n == 0){
        maximum = arr[0];
    }
    else{
        maximum = max(arr[n], MaxSubsequence2(n - 1) + arr[n]);
    }
    return maximum;
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        
        long long answer = -INF;
        for(int i = 0; i < n; i++){
            answer = max(answer, MaxSubsequence2(i));
        }
        cout << answer << endl;
    }
    return 0;
}


// 法三：递归策略+记忆化，时间复杂度O(n^2)
#include <iostream>
#include <cstdio>
#include <cmath>
#include <climits>

using namespace std;

const int MAXN = 1e6 + 10;

long long arr[MAXN];

const int INF = INT_MAX;

long long memo[MAXN];

long long MaxSubsequence3(int n){
    if(memo[n] != -1){
        return memo[n];
    }
    long long maximum;
    if(n == 0){
        maximum = arr[n];
    }
    else{
        maximum = max(arr[n], MaxSubsequence2(n - 1) + arr[n]);
    }
    memo[n] = maximum;
    return maximum;
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        fill(memo, memo + n, -1);
        long long maximum = -INF;
        for(int i = 0; i < n; i++){
            maximum = max(maximum, MaxSubsequence3(i));
        }
        cout << answer << endl;
    }
    return 0;
}
