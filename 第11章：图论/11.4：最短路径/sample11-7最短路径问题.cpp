/*
例题11.7	最短路径问题（浙江大学复试上机题）	
http://t.cn/AilPbME2
*/

#include <iostream>
#include <climits>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

// http://t.cn/AilPbME2

const int MAXN = 1001;  // 点的编号1~1000

const int INF = INT_MAX;  // 无穷大定义为很大的数

struct Edge{  // 邻接表的边的数据结构
    int to;  // 终点
    int length;  // 长度
    int cost;  // 花费
    Edge(int t, int l, int c): to(t), length(l), cost(c){}
};

struct Point{  // 点的数据结构，用于判断离源点最短的距离的点
    int number;  // 点的编号
    int distance;  // 离源点的距离
    Point(int n, int d): number(n), distance(d){}
    bool operator< (const Point& p) const{
        return distance > p.distance;
    }
};

vector<Edge> graph[MAXN];  // 领接表

int dist[MAXN];  // 存放对应编号离源点的最短距离
int cost[MAXN];  // 存放对应编号离源点的最小代价

void Dijkstra(int s){
    priority_queue<Point> PQ;
    dist[s] = 0;
    cost[s] = 0;
    PQ.push(Point(s, dist[s]));
    while(!PQ.empty()){
        int u = PQ.top().number;
        PQ.pop();
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            int len = graph[u][i].length;
            int c = graph[u][i].cost;
            if(dist[v] > dist[u] + len || (dist[v] == dist[u] + len && cost[v] > cost[u] + c)){  // 松弛操作的条件
                dist[v] = dist[u] + len;
                cost[v] = cost[u] + c;
                PQ.push(Point(v, dist[v]));
            }
        }
    }
    return ;
}

int main()
{
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == 0){
            break;
        }
        memset(graph, 0, sizeof(graph));  // 图初始化
        fill(dist, dist + n + 1, INF);  // 距离初始化为无穷，dist[0]弃用
        fill(cost, cost + n + 1, INF);  // 花费初始化为无穷，cost[0]弃用
        while(m--){
            int from, to, len, cost;
            cin >> from >> to >> len >> cost;
            graph[from].push_back(Edge(to, len, cost));
            graph[to].push_back(Edge(from, len, cost));
        }
        int s, t;
        cin >> s >> t;
        Dijkstra(s);
        cout << dist[t] << " " << cost[t] << endl;
    }
    return 0;
}
