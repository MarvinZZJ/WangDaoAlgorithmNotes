/*
习题12.1	吃糖果（北京大学复试上机题）	
http://t.cn/AiQsVyKz
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 20 + 10;

int plan[MAXN];  // 表示有i块巧克力时， 共有plan[i]种吃法。

// 可以利用递推式：plan[i] = plan[i - 1] + plan[i - 2],plan[0] = 1, plan[1] = 1求解

int main()
{
    plan[0] = 1;
    plan[1] = 1;
    for(int i = 2; i < MAXN; i++){
        plan[i] = plan[i - 1] + plan[i - 2];
    }
    int n;
    while(cin >> n){
        cout << plan[n] << endl;
    }
    return 0;
}
