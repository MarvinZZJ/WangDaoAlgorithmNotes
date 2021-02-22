/*
附加题12.1 Longest Ordered Subsequence
http://poj.org/problem?id=2533
*/


// 方法一：朴素递归,时间复杂度O(2^n)
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 10;

int arr[MAXN];

// 此时该函数代表求以arr[n]为末尾元素的最长递增子序列的长度
int LongestOrderedSubsequence(int n){
    int answer;
    if(n == 1){
        answer = 1;
    }
    else{
        answer = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[n]){
                answer = max(answer, LongestOrderedSubsequence(i) + 1);
            }
        }
    }
    return answer;
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int answer = 1;
        for(int i = 1; i <= n; i++){
            answer = max(answer, LongestOrderedSubsequence(i));
        }
        cout << answer << endl;
    }
    return 0;
}




// 方法二：朴素递归+记忆法，时间复杂度O(n^2)
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 10;

int arr[MAXN];

int memo[MAXN];  // memo[i]保存以arr[i]为末尾元素的最长递增子序列的长度

int LongestOrderedSubsequence(int n){
    int answer;
    if(memo[n] != -1){
        return memo[n];
    }
    if(n == 1){
        answer = 1;
    }
    else{
        answer = 1;
        for(int i = 1; i < n; i++){
            if(arr[i] < arr[n]){
                answer = max(answer, LongestOrderedSubsequence(i) + 1);
            }
        }
    }
    memo[n] = answer;
    return answer;
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        memset(memo, -1, sizeof(memo));
        int answer = 1;
        for(int i = 1; i <= n; i++){
            answer = max(answer, LongestOrderedSubsequence(i));
        }
        cout << answer << endl;
    }
    return 0;
}




// 方法三：递推方式，时间复杂度O(n^2)
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 10;

int arr[MAXN];

int dp[MAXN];

// cis
int LongestOrderedSubsequence(int n){
    int answer;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= n; i++){
        if(i == 1){
            dp[i] = 1;
            answer = dp[i];
        }
        else{
            dp[i] = 1;
            for(int j = 1; j < i; j++){
                if(arr[j] < arr[i]){
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            answer = max(answer, dp[i]);
        }
    }
    return answer;
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        int answer = LongestOrderedSubsequence(n);
        cout << answer << endl;
    }
    return 0;
}



// 法四：此时时间复杂度为O(nlogn)
// 利用辅助数组support[MAXN],其中support[i]代表当前长度为i的递增子序列的末尾最小的元素
// 此时support[]数组在构造过程中元素时递增的，所以可以采用二分查找
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 1e3 + 10;

const int INF = INT_MAX;

int arr[MAXN];

int support[MAXN];

int main(){
    int n;
    while(cin >> n){
        for(int i = 1; i <= n; i++){
            cin >> arr[i];
        }
        support[0] = -INF;
        int length = 0;
        for(int i = 1; i <= n; i++){
            if(arr[i] > support[length]){
                support[++length] = arr[i];
            }
            else{
                int pos = lower_bound(support, support + length, arr[i]) - support;  // 查找第一个大于等于arr[i]的support[]值
                support[pos] = arr[i];  // 更新原先的support[pos]值为更小的元素
            }
        }
        cout << length << endl;
    }
    return 0;
}
