/*
例题9.4	Square	
http://poj.org/problem?id=2362
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 25;

int m; // 木棍数目
int side;  // 需构成正方形的边长
int sticks[MAXN];
bool visit[MAXN];

bool Compare(int x, int y){
    return x > y;
}

bool DFS(int sum, int pos, int number){
    // sum:当前边的已拼接长度。pos:当前待判断木棍下标。number：已组合完成的边数
    if(number == 3){
        return true;
    }
    else{
        int frontDismatchLen = 0;  // 剪枝3：记录前一个尝试失败的木棍的长度
        for(int i = pos; i < m; i++){
            if(visit[i] || sticks[i] == frontDismatchLen || sum + sticks[i] > side){
                // 若到目前为止已经用过该木棍或者与前面失配的木棍同长度或者当前木棍与已完成长度sum之和大于边长side
                continue;
            }
            // 状态转移
            visit[i] = true;
            if(sum + sticks[i] == side){  //等于边长
                if(DFS(0, 0, number + 1)){
                    return true;
                }
                else{
                    frontDismatchLen = sticks[i];  // 记录失败木棍长度
                }
            }
            else{
                if(DFS(sum + sticks[i], i + 1, number)){
                    return true;
                }
                else{
                    frontDismatchLen = sticks[i];  // 记录失败木棍长度
                }
            }
            visit[i] = false;
        }
    }
    return false;
}

int main()
{
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        cin >> m;
        int sumLength = 0;  // 记录木棍总长度
        for(int i = 0; i < m; i++){
            cin >> sticks[i];
            sumLength += sticks[i];
        }
        memset(visit, false, sizeof(visit));
        sort(sticks, sticks + m);  // 木棍长度由大到小排序
        side = sumLength / 4;
        if(sumLength % 4 != 0){  // 剪枝1：不能整除4，则必不可能构成正方形
            cout << "no" << endl;
            continue;
        }
        else if(sticks[0] > side){  // 剪枝2：最大木棍长度大于边长
            cout << "no" << endl;
            continue;
        }
        else{
            if(DFS(0, 0, 0)){
                cout << "yes" << endl;
            }
            else{
                cout << "no" << endl;
            }
        }
    }
    return 0;
}
