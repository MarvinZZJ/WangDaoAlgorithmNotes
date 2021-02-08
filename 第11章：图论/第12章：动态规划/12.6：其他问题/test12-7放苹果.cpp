/*
习题12.7	放苹果（北京大学复试上机题）	
http://t.cn/AiQsyOnq
*/


// 代码一：：
#include <iostream>
#include <cstdio>

using namespace std;

/*
    M个苹果放在N个盘子里分法有:dp[M][N], 0 <= M,N <= 10
    设dp(m,n) 为m个苹果，n个盘子的放法数目，则先对n作讨论，
    当m<n：必定有n-m个盘子永远空着，去掉它们对摆放苹果方法数目不产生影响。dp(m,n) = dp(m,m)
    当m>=n：不同的放法可以分成两类：
        1、有至少一个盘子空着，即相当于dp(m,n) = dp(m,n-1);
        2、所有盘子都有苹果，相当于可以从每个盘子中拿掉一个苹果，不影响不同放法的数目，即dp(m,n) = dp(m-n,n).
        而总的放苹果的放法数目等于两者的和，即 dp(m,n) =dp(m,n-1)+dp(m-n,n)
    初始条件说明
        当m=0，n=0时，没苹果，没盘子，定为0种放法。这个条件在计算的时候用不到。题设至少一个盘子一个苹果。
        当m=0，n>0时，没苹果，有盘子，定为1种放法。这个有点抽象，考虑：dp[1][1]=dp[1][0]+dp[0][1]=0+1。
        当m>0，n=0时，有苹果，没盘子，定为0种放法。
        dp两条路，第一条n会逐渐减少，终会到达出口n=0;
        第二条m会逐渐减少，因为n>m时，会计算dp(m,m)　所以终会到达出口m=0．
*/

const int MAXN = 11;

int dp[MAXN][MAXN];

int main()
{
    int m, n;
    while(cin >> m >> n){
        // 1.初始化边界条件
        // 没有盘子时有0种摆法
        for(int i = 0; i <= m; i++){
            dp[i][0] = 0;
        }
        // 没有苹果且盘子数≥1时，有1中摆法
        for(int i = 1; i <= n; i++){
            dp[0][i] = 1;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(i < j){  // 若苹果数＜盘子数(盘子有多余)
                    dp[i][j] = dp[i][i];
                }
                else{  // 若苹果数≥盘子数
                    // 两种情况：
                    // 1.至少有一个盘子空着，此时方案数相当于有i个苹果、j-1个盘子时可以得到的方案数
                    // 2.盘子全有苹果，此时方案数相当于每个盘子去掉一个苹果后的的方案数
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}




代码二：
#include <iostream>>
#include <cstdio>

using namespace std;

const int MAXN = 10 + 10;

int dp[MAXN][MAXN];

int main(){
    int m, n;
    while(cin >> m >> n){
        for(int i = 0; i <= m; i++){
            dp[i][1] = 1;
        }
        for(int j = 0; j <= n; j++){
            dp[0][j] = 1;
        }
        for(int i = 1; i <= m; i++){
            for(int j = 2; j <= n; j++){
                if(i < j){
                    dp[i][j] = dp[i][i];
                }
                else{
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}
