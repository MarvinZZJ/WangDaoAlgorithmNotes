/*
例题11.6	畅通工程续（浙江大学复试上机题）	
http://acm.hdu.edu.cn/showproblem.php?pid=1874
*/

#include <iostream>
#include <cstdio>
#include <queue>
#include <climits>
#include <cstring>
#include <vector>

using namespace std;

// 求单源最短路径问题

const int MAXN = 200 +10;  // 最大城镇数目

const int INF = INT_MAX;  // 无穷设为很大的数

struct Edge{  // 邻接图的边结构
    int to;
    int length;
    Edge(int t, int l): to(t), length(l){}
};

struct Point{
    int number; // 顶点的编号
    int distance;  // 源点到该点的距离
    Point(int n, int d): number(n), distance(d){}
    bool operator< (const Point& p) const {
        return distance > p.distance;
    }
};

vector<Edge> graph[MAXN];  // 领接表实现的图

int dis[MAXN];  // 源点到各结点的距离

void Dijkstra(int start, int n){
    fill(dis, dis + n, INF);  // 距离初始化为无穷
    priority_queue<Point> PQ;  // 用于筛选现在距离源点最近的点
    dis[start] = 0;  // 将源点到源点的距离设为0
    PQ.push(Point(start, dis[start]));  // 源点入优先队列
    while(!PQ.empty()){
        int u = PQ.top().number;  // 获取离源点最近的点的编号
        PQ.pop();                 // 记得弹出优先队列队首元素!!
        // 遍历该点u的所有邻接的边，判断将u作为其邻接点到源点的中间结点时，
        // 新的距离是否小于不经过u这一中间结点时的距离。
        for(int i = 0; i < graph[u].size(); i++){
            int v = graph[u][i].to;
            int length = graph[u][i].length;
            if(dis[u] + length < dis[v]){  // 找到s--->v 更短的路线，更新dis[v]
                dis[v] = dis[u] + length;
                PQ.push(Point(v, dis[v]));  // 入优先队列
            }
        }
    }
    return;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        memset(graph, 0, sizeof(graph));  // 图初始化
        while(m--){
            int from, to, len;
            cin >> from >> to >> len;
            graph[from].push_back(Edge(to, len));
            graph[to].push_back(Edge(from, len));
        }
        int start, terminal;
        cin >> start >> terminal;
        Dijkstra(start, n);
        if(dis[terminal] == INF){
            dis[terminal] = -1;
        }
        cout << dis[terminal] << endl;
    }
    return 0;
}
