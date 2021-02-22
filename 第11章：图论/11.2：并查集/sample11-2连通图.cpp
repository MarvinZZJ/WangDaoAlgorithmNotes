/*
例题11.2	连通图（吉林大学复试上机题）	
http://t.cn/AiO77VoA
*/


#include <iostream>
#include <cstdio>

using namespace std;

// 思路： 利用并查集来判断图的连通性

const int MAXN = 1001;

int father[MAXN];  // father[0]弃用
int height[MAXN];  // height[0]弃用

void Initial(int n){
    for(int i = 0; i <= n; i++){
        father[i] = i;  // 初始化每个结点的父结点为自己
        height[i] = 0;  // 初始化每个结点的高度为0
    }
    return ;
}

// 查找根节点
int FindRoot(int x){
    if(father[x] != x){
        father[x] = FindRoot(father[x]);  // 路径压缩
    }
    return father[x];
}

// 合并集合
void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){  // x与y不在同一集合
        // 矮树作为高树的子树
        if(height[x] > height[y]){
            father[y] = x;
        }
        else if(height[x] < height[y]){
            father[x] = y;
        }
        else{
            father[y] = x;
            height[x]++;
        }
    }
    return ;
}

int main()
{
    int n, m;
    while(cin >> n >> m){
        if(n == 0 && m == n){
            break;
        }
        Initial(n);
        while(m--){
            int x, y;
            cin >> x >> y;
            Union(x, y);
        }
        int answer = 0;  // 连通分量数
        for(int i = 1; i <= n; i++){
            if(i == FindRoot(i)){
                answer++;
            }
        }
        if(answer == 1){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
