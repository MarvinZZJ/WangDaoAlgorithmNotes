/*
例题11.3	Is It A Tree?（北京大学复试上机题）	
http://t.cn/AiO7FyDO
*/


#include <iostream>
#include <cstdio>

using namespace std;

// 1:各个结点需要属于同一个集合
// 2:除根结点入度为零，其他结点入度为1
// 3:根结点只有一个

const int MAXN = 10000;

// 0弃用 (1~9999)
int father[MAXN];
int height[MAXN];
int inDegree[MAXN];
bool visit[MAXN];

// 初始化
void Initial(){
    for(int i = 0; i < MAXN; i++){
        father[i] = i;
        height[i] = 0;
        inDegree[i] = 0;
        visit[i] = false;
    }
    return ;
}

// 查找根结点
int FindRoot(int x){
    if(father[x] != x){
        father[x] = FindRoot(father[x]);
    }
    return father[x];
}

// 合并集合
void Union(int x, int y){
    x = FindRoot(x);
    y = FindRoot(y);
    if(x != y){
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

bool IsTree(){
    int component = 0; // 连通分量数
    int rootNum = 0;  // 根结点数
    bool flag = true;
    for(int i = 1; i < MAXN; i++){
        if(!visit[i]){
            continue;
        }
        else{
            if(FindRoot(i) == i){
                component++;
            }

            if(inDegree[i] == 0){
                rootNum++;
            }
            else if(inDegree[i] > 1){  // 存在结点入度大于1
                flag = false;
            }
        }
    }
    if(component != 1 || rootNum != 1){   // 连通分支不为1或根结点不止1个
        flag = false;
    }
    if(component == 0 && rootNum == 0){  // 空树
        flag = true;
    }
    return flag;
}

int main()
{
    int caseNum = 0;
    int x, y;
    Initial();
    while(cin >> x >> y){
        if(x == -1 && y == -1){
            break;
        }
        if(x == 0 && y == 0){
            if(IsTree()){
                cout << "Case " << ++caseNum <<  " is a tree." << endl;
            }
            else{
                cout << "Case " << ++caseNum <<  " is not a tree." << endl;
            }
            Initial();
        }
        else{
            Union(x, y);
            inDegree[y]++;
            visit[x] = true;
            visit[y] = true;
        }
    }
    return 0;
}
