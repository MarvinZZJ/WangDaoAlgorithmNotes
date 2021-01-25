/*
例题9.3	A Knights's Journey	
http://poj.org/problem?id=2488
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAXN = 30;

bool visit[MAXN][MAXN];

int direction[8][2] = {{-1, -2}, {1, -2}, {-2, -1}, {2, -1},
                        {-2, 1}, {2, 1}, {-1, 2}, {1, 2}};

bool DFS(int x, int y, int step, string trail, int p, int q){
    if(p * q == step){
        cout << trail << endl << endl;
        return true;
    }
    for(int i = 0; i < 8; i++){
        int nextx = x + direction[i][0];
        int nexty = y + direction[i][1];
        if(nextx < 0 || nextx >= p || nexty < 0 || nexty >= q || visit[nextx][nexty]){
            continue;
        }
        visit[nextx][nexty] = true;
        char col = 'A' + nexty;
        char row = '1' + nextx;
        if(DFS(nextx, nexty, step + 1, trail + col + row, p, q)){
            return true;
        }
        visit[nextx][nexty] = false;
    }
    return false;
}

int main(){
    int n, caseNum = 0;
    scanf("%d", &n);
    while(n--){
        int p, q;
        cin >> p >> q;
        memset(visit, false, sizeof(visit));
        cout << "Scenario #" << ++caseNum << ":" << endl;
        visit[0][0] = true;
        if(DFS(0, 0, 1, "A1", p, q)){
            continue;
        }
        else{
            cout << "impossible" << endl << endl;
        }
    }
    return 0;
}
