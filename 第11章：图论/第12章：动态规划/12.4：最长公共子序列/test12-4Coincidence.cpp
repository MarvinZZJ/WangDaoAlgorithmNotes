/*
习题12.4	Coincidence（上海交通大学复试上机题）	
http://t.cn/AiY03RO5
*/


#include <iostream>
#include <cstdio>
#include <string>
#include <cmath>

using namespace std;

const int MAXN = 1e3 + 10;

int dp[MAXN][MAXN];  // dp[i][j]用于保存以s1中第i个元素为末尾及以s2中第j个元素为末尾的子串的最长公共子序列的长度

void CommonSubsequenceLen(string str1, string str2){
    for(int i = 0; i < str1.size(); i++){
        for(int j = 0; j < str2.size(); j++){
            int answer;
            if(i == 0 || j == 0){  // 边界值初始化
                answer = 0;
            }
            else{
                if(str1[i] == str2[j]){
                    answer = 1 + dp[i - 1][j - 1];
                }
                else{
                    answer = max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
            dp[i][j] = answer;
        }
    }
    return;
}

int main(){
    string str1, str2;
    while(getline(cin, str1)){
        getline(cin, str2);
        // 在串头插入一个无用的字符'0',使得字符串下标可以从1开始，便于处理边界情况
        str1.insert(0, 1, '0');
        str2.insert(0, 1, '0');
        CommonSubsequenceLen(str1, str2);
        cout << dp[str1.size() - 1][str2.size() - 1] << endl;
    }
    return 0;
}
