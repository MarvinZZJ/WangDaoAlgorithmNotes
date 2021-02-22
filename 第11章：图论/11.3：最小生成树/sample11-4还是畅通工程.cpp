/*
例题11.4	还是畅通工程（浙江大学复试上机题）	
http://t.cn/AiWud0C6
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100 + 10;

struct Edge{
    int from;
    int to;
    int weight;
    bool operator< (const Edge& e) const {
        return weight < e.weight;
    }
};

struct Node{
    int father;
    int height;
    Node(){}
    Node(int f, int h):father(f), height(h){}
};

Node node[MAXN];
Edge edge[MAXN * MAXN];

void Initial(int n){
    for(int i = 0; i <= n; i++){
        node[i].father = i;
        node[i].height = 0;
    }
    return;
}

int FindRoot(int x){
    if(x != node[x].father){
        node[x].father = FindRoot(node[x].father);
    }
    return node[x].father;
}

void Union(int x, int y){
    x = FindRoot(node[x].father);
    y = FindRoot(node[y].father);
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
    return;
}

int Kruskal(int n, int edgeNum){
    int answer = 0;
    Initial(n);
    sort(edge, edge + edgeNum);
    for(int i = 0; i < edgeNum; i++){
        if(FindRoot(edge[i].from) != FindRoot(edge[i].to)){
            Union(edge[i].from, edge[i].to);
            answer += edge[i].weight;
        }
    }
    return answer;
}

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        int edgeNum = n * (n - 1) / 2;
        for(int i = 0; i < edgeNum; i++){
            cin >> edge[i].from >> edge[i].to >> edge[i].weight;
        }
        cout << Kruskal(n, edgeNum) << endl;
    }
    return 0;
}
