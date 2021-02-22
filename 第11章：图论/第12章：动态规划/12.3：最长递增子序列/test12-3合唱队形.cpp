/*
题12.3	合唱队形（北京大学复试上机题）	
http://t.cn/AiYNyHPe
*/


// 代码一：
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 100 + 10;

int height[MAXN];

int dp1[MAXN];  // (从左至右)存放以height[i]为末尾元素的最长递增子序列的元素个数
int dp2[MAXN];  // (从右至左)存放以height[i]为末尾元素的最长递减子序列的元素个数



void MaxAscendSubsequenceRToL(int n){
    for(int i = 0; i < n; i++){
        dp1[i] = 1;  // 初始化时，表示该子串只有arr[i]这一个元素
        for(int j = 0; j < i; j++){
            if(height[j] < height[i]){
                dp1[i] = max(dp1[i], dp1[j] + 1);
            }
        }
    }
}


void MaxAscendSubsequenceLToR(int n){
    for(int i = n - 1; i >= 0; i--){
        dp2[i] = 1;  // 初始化时，表示该子串只有arr[i]这一个元素
        for(int j = n - 1; j > i; j--){
            if(height[j] < height[i]){
                dp2[i] = max(dp2[i], dp2[j] + 1);
            }
        }
    }
}

int main()
{
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> height[i];
        }
        MaxAscendSubsequenceLToR(n);
        MaxAscendSubsequenceRToL(n);
        int chorusNum = 0;
        for(int i = 0; i < n; i++){
            int current = dp1[i] + dp2[i] - 1;
            if(current > chorusNum){
                chorusNum = current;
            }
        }
        cout << n - chorusNum << endl;
    }
    return 0;
}




// 代码二：
#include <iostream>
#include <cstdio>
#include <climits>
#include <cmath>

using namespace std;

const int MAXN = 100 + 10;

const int INF = INT_MAX;

int height[MAXN];
int ascend[MAXN];
int descend[MAXN];

void MaxAscendSubsequenceLToR(int n){
    for(int i = 0; i < n; i++){
        ascend[i] = 1;
        for(int j = 0; j < i; j++){
            if(height[j] < height[i]){
                ascend[i] = max(ascend[i], ascend[j] + 1);
            }
        }
    }
}

void MaxAscendSubsequenceRToL(int n){
    for(int i = n - 1; i >= 0; i--){
        descend[i] = 1;
        for(int j = n - 1; j > i; j--){
            if(height[i] > height[j]){
                descend[i] = max(descend[i], descend[j] + 1);
            }
        }
    }
}

int main(){
    int n;
    while(cin >> n){
        for(int i = 0; i < n; i++){
            cin >> height[i];
        }
        MaxAscendSubsequenceLToR(n);
        MaxAscendSubsequenceRToL(n);
        int answer = INF;
        for(int i = 0; i < n; i++){
            answer = min(answer, n - ascend[i] - descend[i] + 1);
        }
        cout << answer << endl;
    }
    return 0;
}
