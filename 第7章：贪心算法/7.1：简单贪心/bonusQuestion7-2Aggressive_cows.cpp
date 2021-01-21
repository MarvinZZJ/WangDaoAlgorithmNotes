/*
附加题7.2 Aggressive cows
http://poj.org/problem?id=2456
思路：将求最大的最小值问题转化为求一个判定性问题，对于该题
      即为利用二分法求某个最小距离下，是否符合题意，从而求出
      最大的最小距离
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e6 + 10;

int arr[MAXN];

bool Judge(int n, int m, int distance){
    int current = arr[0];
    int num = 1;
    for(int i = 1; i < n; i++){
        if(arr[i] - current >= distance){
            current = arr[i];
            num++;
        }
        if(num >= m){
            return true;
        }
    }
    return false;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        for(int i = 0; i < n; i++){
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int left = 1, right = arr[n - 1] - arr[0];
        //  利用二分查找，找出符合条件的最大的最小值
        while(left <= right){
            int mid = (right - left) / 2 + left;
            if(Judge(n, m, mid)){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        cout << right << endl;
    }
}
