/*
例题11.10	Instructions Arrangement	
http://acm.hdu.edu.cn/showproblem.php?pid=4109
*/


#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include<cstring>

using namespace std;

const int MAXN = 1000;
const int INF = INT_MAX;  // 无穷大定义为很大的数

struct Edge{
    int to;
    int length;
    Edge(int t, int l): to(t), length(l){}
};

vector<Edge> graph[MAXN];  // 邻接表
int inDegree[MAXN];  // 入度数
int earliest[MAXN];  // 最早开始时间
int latest[MAXN];  // 最晚开始时间


// 求关键路径（利用拓扑排序）
void CriticalPath(int n){
    vector<int> topology;  // 保存拓扑序列
    queue<int> node;
    // 可以加入拓扑序列的点加入node队列中
    for(int i = 0; i < n; i++){
        if(inDegree[i] == 0){
            node.push(i);
            earliest[i] = 1;  // 最早开始时间初始化为1
        }
    }
    while(!node.empty()){
        int u = node.front();
        node.pop();
        topology.push_back(u);  // 加入拓扑序列
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            int len = graph[u][i].length;
            inDegree[v]--;
            earliest[v] = max(earliest[v], earliest[u] + len);
            if(inDegree[v] == 0){
                node.push(v);
            }
        }
    }
    for(int i = topology.size() - 1; i >= 0; i--){
        int u = topology[i];
        if(graph[u].size() == 0){  // 汇点的最晚开始时间初始化
            latest[u] = earliest[u];
        }
        else{  // 非汇点的最晚开始时间初始化
            latest[u] = INF;
        }
        for(int j = 0; j < graph[u].size(); j++){
            int v = graph[u][j].to;
            int len = graph[u][j].length;
            latest[u] = min(latest[u], latest[v] - len);
        }
    }
    return ;
}


int main()
{
    int n, m;
    while(cin >> n >> m){
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        memset(earliest, 0, sizeof(earliest));
        memset(latest, 0, sizeof(latest));
        while(m--){
            int from, to, length;
            cin >> from >> to >> length;
            graph[from].push_back(Edge(to, length));
            inDegree[to]++;
        }
        CriticalPath(n);
        int answer = 0;
        for(int i = 0; i < n; i++){
            answer = max(answer, earliest[i]);
        }
        cout << answer << endl;
    }
    return 0;
}
