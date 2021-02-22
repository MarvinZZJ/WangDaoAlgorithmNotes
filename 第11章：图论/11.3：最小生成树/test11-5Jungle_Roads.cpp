/*
习题11.5	Jungle Roads（北京大学复试上机题）	
http://t.cn/AiW33P91
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <algorithm>

using namespace std;

const int MAXN = 27 + 5;

struct NodeInfo{
    int father;
    int height;
};

struct Edge{
    int from, to;
    int cost;
    bool operator< (const Edge& e) const{
        return cost < e.cost;
    }
};

map<int, NodeInfo> node;  // 将A~Z分别替换为0~25作为key

Edge edge[MAXN * MAXN];

int FindRoot(int x){
    if(x != node[x].father){
        node[x].father = FindRoot(node[x].father);
    }
    return node[x].father;
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){
        if(node[x].height < node[y].height){
            node[x].father = y;
        }
        else if(node[x].height > node[y].height){
            node[y].father = x;
        }
        else{
            node[y].father = x;
            node[x].height++;
        }
    }
    return;
}

int Kruskal(int edgeNum){
    int answer = 0;
    sort(edge, edge + edgeNum);  // 将每条路按照代价cost由小到大排序
    for(int i = 0; i < edgeNum; i++){
        if(FindRoot(edge[i].from) != FindRoot(edge[i].to)){
            Union(edge[i].from, edge[i].to);
            answer += edge[i].cost;
        }
    }
    return answer;
}

int main(){
    int n;
    while(cin >> n){
        cin.ignore(1024, '\n');
        if(n == 0){
            break;
        }
        int edgeNum = 0;  // 统计总共有多少条路
        for(int i = 1; i < n; i++){
            char from;
            int num;
            cin >> from >> num;
            while(num--){
                char to;
                int cost;
                cin >> to >> cost;
                // 添加该路径
                edge[edgeNum].from = from - 'A';
                edge[edgeNum].to = to - 'A';
                edge[edgeNum++].cost = cost;
                if(node.find(from - 'A') == node.end()){  // 点集还没有该点，则添加
                    node[from - 'A'].father = from - 'A';
                    node[from - 'A'].height = 0;
                }
                if(node.find(to - 'A') == node.end()){  // 点集还没有该点，则添加
                    node[to - 'A'].father = to - 'A';
                    node[to - 'A'].height = 0;
                }
            }
            cin.ignore(1024, '\n');
        }
        cout << Kruskal(edgeNum) << endl;
        node.clear();  // 清空map，为下一次输入集做准备
    }
}
