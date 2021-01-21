/*
附加题7.1 箱子打包
https://acm.ecnu.edu.cn/problem/1045/
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 1e5 + 10;

int length[MAXN];

int main()
{
    int n, l;
    scanf("%d%d", &n, &l);
    for(int i = 0; i < n; i++){
        scanf("%d", &length[i]);
    }
    sort(length, length + n);
    int left = 0, right = n - 1;
    int q = 0;
    while(left <= right){
        if(length[left] + length[right] <= l){
            left++;
            right--;
        }
        else{
            right--;
        }
        q++;
    }
    printf("%d\n", q);
    return 0;
}
