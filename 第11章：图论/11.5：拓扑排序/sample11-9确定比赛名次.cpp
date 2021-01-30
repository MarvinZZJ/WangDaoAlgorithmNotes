/*
例题11.9	确定比赛名次	
http://acm.hdu.edu.cn/showproblem.php?pid=1285
*/

#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 501;  // 编号1~500,0作废

vector<int> graph[MAXN];  // 邻接图
int inDegree[MAXN];  // 每个顶点的入度数


// 拓扑排序
vector<int> TopologicalSort(int n){
    vector<int> topology;  // 保存拓扑序列
    priority_queue<int, vector<int>, greater<int> > node;
    for(int i = 1; i <= n; i++){
        if(inDegree[i] == 0){
            node.push(i);
        }
    }
    while(!node.empty()){
        int u = node.top();
        node.pop();
        topology.push_back(u);
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i];
            inDegree[v]--;
            if(inDegree[v] == 0){
                node.push(v);
            }
        }
    }
    return topology;
}


int main()
{
    int n, m;
    while(cin >> n >> m){
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        while(m--){
            int from, to;
            cin >> from >> to;
            graph[from].push_back(to);
            inDegree[to]++;
        }
        vector<int> answer = TopologicalSort(n);
        for(int i = 0; i < answer.size(); i++){
            if(i == answer.size() - 1){
                cout << answer[i] << endl;
            }
            else{
                cout << answer[i] << " ";
            }
        }
    }
    return 0;
}
