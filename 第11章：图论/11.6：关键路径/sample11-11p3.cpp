/*
例题11.11	p3（清华大学复试上机题）
*/

#include <iostream>
#include <climits>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;


const int MAXN = 1e5 + 10;
const int INF = INT_MAX;  // 无穷设为很大的数
const int MOD = 1e9 + 7;

vector<int> graph[MAXN];  // 邻接表存储有向图

int inDegree[MAXN];  // 入度数

long long earliest[MAXN];  // 最早开始时间
long long latest[MAXN];  // 最晚开始时间
long long time[MAXN];  // 花费时间


long long CriticalPath(int n){
    vector<int> topology;  // 存放关键路径
    queue<int> node;  // 存放入度为0的点
    long long totalTime = 0;  // 保存完成任务需要的最短时间
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){
            node.push(i);
            totalTime = max(totalTime, earliest[i] + time[i]);  // 当i入度为0时，计算完成该任务i最少所需时间
        }
    }

    while(!node.empty()){
        int u = node.front();
        node.pop();
        topology.push_back(u);
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            earliest[v] = max(earliest[v], earliest[u] + time[u]);  // 更新v的最早开始时间
            inDegree[v]--;
            if(inDegree[v] == 0){
                node.push(v);
                totalTime = max(totalTime, earliest[v] + time[v]);  // 当v入度为0时，计算完成该任务v最少所需时间
            }
        }
        // 计算每个任务最晚开始时间
        for(int i = topology.size() - 1; i >= 0; i--){
            int u = topology[i];
            if(graph[u].size() == 0){  // u为汇点（出度为零的点）
                // latest[u] = earliest[u]; (错误！！！）
                latest[u] = totalTime - time[u];  // 汇点可能有多个，最晚开始时间应该是全部任务的最早完成时间totalTime减去该汇点任务所需时间
            }
            else{  // u为非汇点
                latest[u] = INF;
            }
            for(int i = 0; i < graph[u].size(); i++){
                int v = graph[u][i];
                latest[u] = min(latest[u], latest[v] - time[u]);
            }
        }
    }
    return totalTime;
}


int main()
{
    int n, m;
    while(cin >> n >> m){
        // 初始化
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        memset(earliest, 0, sizeof(earliest));
        memset(latest, 0, sizeof(latest));
        memset(time, 0, sizeof(time));
        // 输入n个任务所需时间， 0号弃用，任务从1开始编号！
        for(int i = 1; i <= n; i++){
            cin >> time[i];
        }
        while(m--){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            inDegree[to]++;
        }
        long long totalTime = CriticalPath(n);
        long long answer = 1;
        for(int i = 1; i <= n; i ++){
            answer *= latest[i] - earliest[i] + 1;
            answer %= MOD;
        }
        cout << totalTime << endl;
        cout << answer << endl;
    }
    return 0;
}
