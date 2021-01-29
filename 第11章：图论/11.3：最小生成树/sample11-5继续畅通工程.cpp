/*
例题11.5	继续畅通工程（浙江大学复试上机题）	
http://t.cn/AiW3fcfp
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct Edge{
    int from;
    int to;
    int cost;
    bool operator< (const Edge& e) const{
        return cost < e.cost;
    }
};

struct Node{
    int father;
    int height;
};

Edge edge[MAXN * (MAXN - 1) / 2];
Node node[MAXN];

void Initial(int n){
    for(int i = 0; i <= n; i++){
        node[i].father = i;
        node[i].height = 0;
    }
    return ;
}

int FindRoot(int x){
    if(node[x].father != x){
        node[x].father = FindRoot(node[x].father);
    }
    return node[x].father;
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){
        if(node[x].height > node[y].height){
            node[y].father = x;
        }
        else if(node[x].height < node[y].height){
            node[x].father = y;
        }
        else{
            node[y].father = x;
            node[x].height++;
        }
    }
    return ;
}

int Kruskal(int n, int edgeNumber){
    Initial(n);  // 初始化村庄顶点
    sort(edge, edge + edgeNumber);
    int sumCost = 0;
    for(int i = 0; i < edgeNumber; i++){
        if(FindRoot(edge[i].from) != FindRoot(edge[i].to)){
            Union(edge[i].from, edge[i].to);
            sumCost += edge[i].cost;
        }
    }
    return sumCost;
}

int main()
{
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        int edgeNum = n * (n - 1) / 2;
        for(int i = 0; i < edgeNum; i++){
            int hasBuilt;
            cin >> edge[i].from >> edge[i].to >> edge[i].cost >> hasBuilt;
            if(hasBuilt){  // 已修建，则代价为0
                edge[i].cost = 0;
            }
        }
        int answer = Kruskal(n, edgeNum);
        cout << answer << endl;
    }
    return 0;
}
