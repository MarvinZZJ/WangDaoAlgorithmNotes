/*
习题11.2	第一题（上海交通大学复试上机题）	
http://t.cn/AiOhkgMJ
*/


// 方法一：使用map存储father，height
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<int, int> father;
map<int, int> height;

int FindRoot(int x){
    if(father.find(x) != father.end()){  // 在father中已有结点x
        if(father[x] != x){
            father[x] = FindRoot(father[x]);
        }
    }
    else{  // 未出现过该结点
        father[x] = x;
        height[x] = 0;
    }
    return father[x];
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){  // x与y不在同一个并查集
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
    int x, y;
    while(cin >> x >> y){
        Union(x, y);
    }
    int component = 0;
    map<int, int>::iterator iter = father.begin();
    for(; iter != father.end(); iter++){
        if(iter->first == FindRoot(iter->first)){
            component++;  // 若其根结点为其自身，则说明发现一个连通子图
        }
    }
    cout << component << endl;

    return 0;
}




// 方法二：利用数组
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000000;

int father[MAXN];
int height[MAXN];
bool visit[MAXN];

void Initial(){
    for(int i = 0; i < MAXN; i++){
        father[i] = i;
        height[i] = 0;
        visit[i] = false;
    }
    return ;
}

int FindRoot(int x){
    if(father[x] != x){
        father[x] = FindRoot(father[x]);  // 压缩路径
    }
    return father[x];
}

void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){  // x与y不在同一个并查集
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
    int x, y;
    Initial();
    while(cin >> x >> y){
        visit[x] = true;
        visit[y] = true;
        Union(x, y);
    }
    int component = 0;  // 连通分支数
    for(int i = 0; i < MAXN; i++){
        if(!visit[i]){
            continue;
        }
        if(FindRoot(i) == i){
            component++;
        }
    }
    cout << component << endl;

    return 0;
}
