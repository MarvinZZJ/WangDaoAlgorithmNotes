/*
例题11.8	Legal or Not	
http://acm.hdu.edu.cn/showproblem.php?pid=3342
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int MAXN = 100 + 10;

vector<int> graph[MAXN];  // 邻接表

int inDegree[MAXN];  // 入度数

bool TopologicalSort(int n){
    queue<int> Q;
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            Q.push(i);
        }
    }
    int number = 0;  // 统计已加入拓扑序列顶点数
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        number++;
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                Q.push(v);
            }
        }
    }
    return (number == n);
}

int main(){
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        for(int i = 0; i < m; i++){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            inDegree[to]++;
        }
        if(TopologicalSort(n)){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
