/*
例题12.6	Common Subsequence	
http://acm.hdu.edu.cn/showproblem.php?pid=1159
*/


#include <iostream>
#include <string>

using namespace std;

string s1;
string s2;

int main()
{
    while(cin >> s1 >> s2){
        const int s1Len = s1.size();
        const int s2Len = s2.size();
        int dp[s1Len + 1][s2Len + 1];  // dp[i][j]用于保存以s1中第i个元素为末尾即以s2中第j个元素为末尾的最长公共子序列的长度
        s1.insert(0, 1, '0');  // 在串头插入一个无用的字符'0',使得字符串下标可以从1开始，便于处理边界情况
        s2.insert(0, 1, '0');
        for(int i = 0; i <= s1Len; i++){
            for(int j = 0; j <= s2Len; j++){
                if(i == 0 || j == 0){  // 边界值处理，即存在一个串为空子串时，最长公共子序列长度将一定为0
                    dp[i][j] = 0;
                    continue;
                }
                if(s1[i] == s2[j]){  // 当前两个末尾元素相同时
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else{  // 当前两个末尾元素不同时
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        cout << dp[s1Len][s2Len] << endl;
    }
    return 0;
}




// 方法一：朴素递归，时间复杂度O(2^(n+m))
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 1000 + 10;

int dp[MAXN][MAXN];

string str1, str2;

int CommonSubsequenceLen(int n, int m){
    int answer;
    if(n == 0 || m == 0){
        answer = 0;
    }
    else{
        if(str1[n] == str2[m]){
            answer = CommonSubsequenceLen(n - 1, m - 1) + 1;
        }
        else{
            answer = max(CommonSubsequenceLen(n, m - 1), CommonSubsequenceLen(n - 1, m));
        }
    }
    return answer;
}

int main(){
    while(cin >> str1 >> str2){
        str1.insert(0, 1, '0');
        str2.insert(0, 1, '0');
        int answer = CommonSubsequenceLen(str1.size() - 1, str2.size() - 1);
        cout << answer << endl;
    }
    return 0;
}




// 方法二：朴素递归+记忆法，时间复杂度O(n*m)
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string str1, str2;

const int MAXN = 1e3 + 10;

int memo[MAXN][MAXN];

int CommonSubsequenceLen(int n, int m){
    if(memo[n][m] != -1){
        return memo[n][m];
    }
    int answer;
    if(n == 0 || m == 0){
        answer = 0;
    }
    else{
        if(str1[n] == str2[m]){
            answer = CommonSubsequenceLen(n - 1, m - 1) + 1;
        }
        else{
            answer = max(CommonSubsequenceLen(n, m - 1), CommonSubsequenceLen(n - 1, m));
        }
    }
    memo[n][m] = answer;
    return answer;
}

int main(){
    while(cin >> str1 >> str2){
        memset(memo, -1, sizeof(memo));
        str1.insert(0, 1, '0');
        str2.insert(0, 1, '0');
        int answer = CommonSubsequenceLen(str1.size() - 1, str2.size() - 1);
        cout << answer << endl;
    }
    return 0;
}




// 方法三：递推法，时间复杂度O(n*m)
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>

using namespace std;

const int MAXN = 1000 + 10;

string str1, str2;

int dp[MAXN][MAXN];

void CommonSubsequenceLen(int len1, int len2){
    for(int i = 0; i < len1; i++){
        for(int j = 0; j < len2; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }
            else{
                if(str1[i] == str2[j]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
        }
    }
    return;
}

int main(){
    while(cin >> str1 >> str2){
        str1.insert(0, 1, '0');
        str2.insert(0, 1, '0');
        CommonSubsequenceLen(str1.size(), str2.size());
        cout << dp[str1.size() - 1][str2.size() - 1] << endl;
    }
    return 0;
}
