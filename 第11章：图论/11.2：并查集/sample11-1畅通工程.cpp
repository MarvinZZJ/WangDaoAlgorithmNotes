/*
例题11.1	畅通工程（浙江大学复试上机题）	
http://t.cn/AiOvBHj9
*/


#include <iostream>
#include <cstdio>

using namespace std;

// 利用并查集的思想

const int MAXN = 1001;  // 0弃用
int father[MAXN];  // 保存各结点的父结点
int height[MAXN];  // 接点高度

void Initial(int n){
    for(int i = 0; i <= n; i++){
        father[i] = i;  // 初始化每个结点的父结点都为自己
        height[i] = 0;  // 初始化高度为0
    }
    return ;
}

int FindRoot(int x){  // 查找根节点
    if(x != father[x]){  // 路径压缩
        father[x] = FindRoot(father[x]);
    }
    return father[x];
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){  // x与y不属于同一集合
        //  将矮树作为高树的子树
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
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        int m;
        cin >> m;
        Initial(n);  // 初始化

        while(m--){
            int x, y;
            cin >> x >> y;
            Union(x, y);  // 合并x与y所在的集合
        }

        // answer = 查找集合数目 - 1
        int answer = -1;
        for(int i = 1; i <= n; i++){
            if(i == FindRoot(i)){  // 找到一个集合的根结点
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}
