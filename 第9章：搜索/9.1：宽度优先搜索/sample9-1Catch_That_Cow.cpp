/*
例题9.1	Catch That Cow	
http://poj.org/problem?id=3278
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int MAXN = 1e5 + 1;

struct Status{
    int pos;
    int time;
    Status(){}
    Status(int p, int  t):pos(p), time(t){}
};

bool visit[MAXN];

int BFS(int n, int k){
    queue<Status> myQueue;
    myQueue.push(Status(n, 0));
    memset(visit, false, sizeof(visit));
    visit[n] = true;
    while(!myQueue.empty()){
        Status current = myQueue.front();
        myQueue.pop();
        if(current.pos == k){
            return current.time;
        }
        // 一次考虑下一步可能的三种状态
        if(current.pos - 1 >= 0 && visit[current.pos - 1] == false){
            myQueue.push(Status(current.pos - 1, current.time + 1));
            visit[current.pos - 1] = true;

        }
        if(current.pos + 1 < MAXN && visit[current.pos + 1] == false){
            myQueue.push(Status(current.pos + 1, current.time + 1));
            visit[current.pos + 1] = true;
        }
        if(current.pos * 2 < MAXN && visit[current.pos * 2] == false){
            myQueue.push(Status(current.pos * 2, current.time + 1));
            visit[current.pos * 2] = true;
        }
    }
    return -1;
}

int main(){
    int n, k;
    while(cin >> n >> k){
        cout << BFS(n, k) << endl;
    }
    return 0;
}
