/*
习题7.2	To Fill or Not to Fill（浙江大学复试上机题）	
http://dwz.date/b2tj
*/



//  方法一：
// 利用贪心策略：
// ①给输入的加油站按油价由小到大排序
// ②创建一个flag[30001]数组来记录走过的路程，若所有加油站遍历完仍然存在flag[i] == 0,则说明无法走完全程

#include <iostream>
#include <algorithm>
#include <queue>
#include <cstdio>

using namespace std;

struct Station{
    double pi;
    double di;
    bool operator<(const Station& x) const{
        return pi < x.pi;
    }
};

const int MAXN = 501;
const int MAXD = 30001;
Station station[MAXN];

int flag[MAXD];

int main(){
    int Cmax, D, Davg, n;
    while(cin >> Cmax >> D >> Davg >> n){
        for(int i = 0; i < n; i++){
            cin >> station[i].pi >> station[i].di;
        }
        sort(station, station + n);

        double sum = 0;
        double maxdistance = Cmax * Davg;
        for(int i = 0; i < n; i++){
            double destination = ((station[i].di + maxdistance) > D ? D : station[i].di + maxdistance);
            double realGo = 0; // 真实需要耗费油量的距离
            for(int j = station[i].di + 1; j <= destination; j++){
                if(flag[j] == 0){
                    flag[j]++;
                    realGo++;
                }
            }
            sum += (realGo / Davg * station[i].pi);
        }
        bool has = true;
        int pos = 1;
        while(has && pos <= D){
            if(!flag[pos]){
                has = false;
                continue;
            }
            pos++;
        }
        if(has){
            printf("%.2f\n", sum);
        }
        else{
            printf("The maximum travel distance = %.2f\n", (double)(pos - 1));
        }
    }
}



//  法二：
//  模拟汽车行驶时的决策，加油站按距离排序
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

struct Station{
    double pi;
    double di;
    bool operator<(const Station& x) const{
        return di <= x.di;
    }
};

const int MAXN = 501;

const int INF = INT_MAX;

Station station[MAXN];

int main(){
    int Cmax, D, Davg, n;
    while(cin >> Cmax >> D >> Davg >> n){
        for(int i = 0; i < n; i++){
            cin >> station[i].pi >> station[i].di;
        }
        station[n].di = D;
        station[n].pi = 0;
        sort(station, station + n);

        if(station[0].di != 0){
            printf("The maximum travel distance = %.2f\n", 0.0);
            continue;
        }

        double maxDistance = Cmax * Davg;
        double gas = 0;  // 当前tank里已有油量
        double currentDis = station[0].di;  // 当前所在的位置
        double currentPrice = station[0].pi;  // 当前的油价
        int index = 0;  // 当前所在加油站的下标序号
        double sum = 0;  // 当前需要的钱数
        bool canReach = true;
        while(currentDis < D){
            bool hasLowerPri = false;  //
            double newDistance = 0;
            double newPrice = INF;
            for(int i = index + 1; i <= n && station[i].di <= currentDis + maxDistance; i++){
                //  若在当前最大行驶距离内出现了价格更低的加油站，则让tank里的油刚好可以到达该加油站即可
                if(currentPrice >= station[i].pi){
                    sum += ((station[i].di - currentDis) / Davg - gas) * currentPrice;
                    gas = 0;
                    index = i;
                    currentDis = station[i].di;
                    currentPrice = station[i].pi;
                    hasLowerPri = true;
                    break;
                }
                else if(station[i].pi < newPrice){
                    newPrice = station[i].pi;
                    newDistance = station[i].di;
                    index = i;
                }
            }
            //  当最大行驶距离中没有比当前所在加油站更低的油价时：
            //  1）此时最大行驶距离也没有一个加油站，即无法行驶到目的地
            if(!hasLowerPri && newPrice == INF){
                printf("The maximum travel distance = %.2f\n", currentDis + maxDistance);
                canReach = false;
                break;
            }
            //  2）此时最大行驶距离里有一个相对其它有最小油价的加油站
            //     此时将tank加满当前加油站的油，行驶到有newPrice的加油站
            if(!hasLowerPri && newPrice != INF){
                sum += (Cmax - gas) * currentPrice;
                gas = Cmax - (newDistance - currentDis) / Davg;
                currentDis = newDistance;
                currentPrice = newPrice;
            }
        }
        if(canReach){
            printf("%.2f\n", sum);
        }
    }
    return 0;
}
