/*
例题7.5	Case of Fugitive	
http://codeforces.com/problemset/problem/555/B
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int MAXN = 2 * 1e5 + 10;

struct Bridge{
    long long length;
    long long index;
};

struct Island{
    long long left;
    long long right;
};

struct Interval{
    long long minimal;
    long long maximal;
    long long index;
    bool operator<(Interval x) const{
        return maximal > x.maximal;
    }
};

Bridge bridge[MAXN];
Interval interval[MAXN];
Island island[MAXN];
long long answer[MAXN];

bool IntervalCompare(Interval x, Interval y){
    if(x.minimal == y.minimal){
        return x.maximal <= y.maximal;
    }
    else{
        return x.minimal == y.minimal;
    }
}

bool BridgeCompare(Bridge x, Bridge y){
    return x.length < y.length;
}

bool Solve(int n, int m){
    int num = 0;  // 已搭建的桥梁数
    int pos = 0;  // 当前区间的下标
    priority_queue<Interval> myQueue;
    for(int i = 0; i < m; i++){
        if(!myQueue.empty() && bridge[i].length > myQueue.top().maximal){
           break;  // 说明有一个区间当前最小的桥梁也没法搭建，此时说明已经无解
        }
        // 将符合建桥条件的区间放入队列
        while(pos < n - 1 &&
              bridge[i].length >= interval[pos].minimal &&
              bridge[i].length <= interval[pos].maximal){
            myQueue.push(interval[pos++]);
        }
        if(!myQueue.empty()){
            Interval current = myQueue.top();
            myQueue.pop();
            answer[current.index] = bridge[i].index;
            num++;
        }
    }
    return num == n - 1;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        memset(island, 0, sizeof(island));
        memset(bridge, 0, sizeof(bridge));
        memset(interval, 0, sizeof(interval));
        memset(answer, 0, sizeof(answer));
        for(int i = 0; i < n; i++){
            cin >> island[i].left >> island[i].right;
        }
        for(int i = 0; i < m; i++){
            cin >> bridge[i].length;
            bridge[i].index = i + 1;
        }
        for(int i = 0; i < n - 1; i++){
            interval[i].index = i;
            interval[i].minimal = island[i + 1].left - island[i].right;
            interval[i].maximal = island[i + 1].right - island[i].left;
        }
        // 将区间先按最小区间值从小到大排序，若相等，再按最大区间从小到大排序。
        sort(interval, interval + n, IntervalCompare);
        // 将桥按长度从小到大排序
        sort(bridge, bridge + m, BridgeCompare);
        if(Solve(n, m)){
            cout << "YES" << endl;
            for(int i = 0; i < n - 1; i++){
                cout << answer[i] << ' ';
            }
            cout << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
