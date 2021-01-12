/*
习题3.5	找最小数（北京邮电大学复试上机题）	
http://t.cn/E9gekWa
*/

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct Point {
    int x;
    int y;
};

const int INF = INT_MAX;
const int MAXN = 1000 + 10;

Point arr[MAXN];

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        Point current, minpoint;
        minpoint.x = INF;
        minpoint.y = INF;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &current.x, &current.y);
            if(current.x < minpoint.x || (current.x == minpoint.x && current.y < minpoint.y)){
                minpoint = current;
            }
        }
        printf("%d %d\n", minpoint.x, minpoint.y);
    }
    return 0;
}
