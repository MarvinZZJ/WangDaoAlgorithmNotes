/*
例题12.1	N阶楼梯上楼问题（华中科技大学复试上机题）	
http://t.cn/Aij9Fr3V
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 90 + 10;

int dp[MAXN];

int main(){
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3; i < MAXN; i++){
        dp[i] = dp[i - 2] + dp[i - 1];
    }
    int n;
    while(cin >> n){
        cout << dp[n] << endl;
    }
}
