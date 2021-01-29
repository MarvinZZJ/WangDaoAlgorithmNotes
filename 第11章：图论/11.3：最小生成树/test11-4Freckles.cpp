/*
习题11.4	Freckles（北京大学复试上机题）	
http://t.cn/AiW3Hbqr
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

// http://t.cn/AiW3Hbqr

// 思路：相当于求最小生成树的权值之和

const int MAXN = 100;

struct Point{  // 点的坐标
    double x;
    double y;
    int father;
    int height;
};

struct Edge{
    int from;  // 存储point数组的下标，作为该点的标识
    int to;  // 存储point数组的下标，作为该点的标识
    double length;
    bool operator< (const Edge& e){
        return length < e.length;
    }
};

Point point[MAXN];
Edge edge[MAXN * (MAXN - 1) / 2];

// 寻找根结点
int FindRoot(int x){
    if(point[x].father != x){
        point[x].father = FindRoot(point[x].father);
    }
    return point[x].father;
}

// 集合合并
void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){  // 两个点不属于同一个集合，则合并
        // 矮树作为高树的子树
        if(point[x].height > point[y].height){
            point[y].father = x;
        }
        else if(point[x].height < point[y].height){
            point[x].father = y;
        }
        else{
            point[y].father = x;
            point[x].height++;
        }
    }
    return ;
}

double Kruskal(int edgeNumber){
    double sumLength = 0;
    sort(edge, edge + edgeNumber);  // 边edge按length从小到大排序
    for(int i = 0; i < edgeNumber; i++){
        if(FindRoot(edge[i].from) != FindRoot(edge[i].to)){  // 两点分别属于不同集合，则添加该边
            Union(edge[i].from, edge[i].to);
            sumLength += edge[i].length;
        }
    }
    return sumLength;
}


int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        // 对n个point进行初始化
        for(int i = 0; i < n; i++){
            //cin >> point[i].x >> point[i].y;
            scanf("%lf%lf", &point[i].x, &point[i].y);
            //printf("x:%.2f, y:%.2f\n", point[i].x, point[i].y);
            point[i].father = i;
            point[i].height = 0;
        }
        // 求出各个顶点间的距离，并存于edge数组
        int edgeNum = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                double diffX = point[i].x - point[j].x;
                double diffY = point[i].y - point[j].y;
                double length = sqrt(diffX * diffX + diffY * diffY);
                //printf("两点距离为：%.2lf\n", length);
                edge[edgeNum].from = i;
                edge[edgeNum].to = j;
                edge[edgeNum].length = length;
                edgeNum++;
            }
        }
        // 利用Kruskal求最小生成树的思想
        double answer = Kruskal(edgeNum);
        printf("%.2f\n", answer);
    }
    return 0;
}
