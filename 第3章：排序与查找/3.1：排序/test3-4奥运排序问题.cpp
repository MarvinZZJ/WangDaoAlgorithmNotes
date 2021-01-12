/*
习题3.4	奥运排序问题（浙江大学复试上机题）	
http://t.cn/E9gYpyl
*/


//  法一：
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Nation {
    int gold_num;
    int prize_num;
    double population;
    double result[4];  // 分解记录金牌数，总奖牌数，金牌比例，总奖牌比例
    int ranking[4] = {1, 1, 1, 1};  // 用于存储上面各值的排名，默认都为第一名
};

int main(){
    int nation_num, need_show;
    while(scanf("%d%d", &nation_num, &need_show) != EOF){
        Nation nat[nation_num];
        int need[need_show];
        for(int i = 0; i < nation_num; i++){
            cin >> nat[i].gold_num >> nat[i].prize_num;
            cin >> nat[i].population;
            nat[i].result[0] = nat[i].gold_num;
            nat[i].result[1] = nat[i].prize_num;
            nat[i].result[2] = nat[i].gold_num / nat[i].population;
            nat[i].result[3] = nat[i].prize_num / nat[i].population;
            if(nat[i].population == 0 && nat[i].gold_num == 0){
                nat[i].result[2] = 0;
            }
            if(nat[i].population == 0 && nat[i].prize_num == 0){
                nat[i].result[3] = 0;
            }
        }
        for(int i = 0; i < need_show; i++){
            cin >> need[i];
        }
        int now_comp;
        for(int i = 0; i < nation_num; i++){
            now_comp = 0;
            while(now_comp < 4){
                for(int j = 0; j < nation_num; j++){
                    if(nat[i].result[now_comp] < nat[j].result[now_comp]){
                        nat[i].ranking[now_comp]++;
                    }
                }
                now_comp++;
            }
        }
        for(int i = 0; i < need_show; i++){
            int best = 100000, res_loc;
            for(int j = 0; j < 4; j++){
                if(best > nat[need[i]].ranking[j]){
                    best = nat[need[i]].ranking[j];
                    res_loc = j;
                }
            }
            printf("%d:%d\n", best, res_loc + 1);
        }
        cout << endl;
    }
    return 0;
}



//  法二：
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <climits>

using namespace std;

const int MAXN = 200 + 10;
const double INF = INT_MAX;

struct Nation {
    int id;
    double gold, medal, goldRate, medalRate;
    int bestMethod, bestOrder;
    int order[4];
    Nation() {}
    Nation(int id, int gold, int medal, int people){
        this->id = id;
        this->gold = gold;
        this->medal = medal;
        bestMethod = MAXN;
        bestOrder = MAXN;
        if(people == 0 && gold != 0){
            goldRate = INF;
        }
        else{
            goldRate = gold / (double)people;
        }
        if(people == 0 && medal != 0){
            medalRate = INF;
        }
        else{
            medalRate = medal / (double)people;
        }
    }
};

Nation arr[MAXN];

bool CompareID(Nation x1, Nation x2){
    return x1.id < x2.id;
}

bool CompareGold(Nation x1, Nation x2){
    return x1.gold > x2.gold;
}

bool CompareMedal(Nation x1, Nation x2){
    return x1.medal > x2.medal;
}

bool CompareGoldRate(Nation x1, Nation x2){
    return x1.goldRate > x2.goldRate;
}

bool CompareMedalRate(Nation x1, Nation x2){
    return x1.medalRate > x2.medalRate;
}

void Solve(int n){
    sort(arr, arr + n, CompareGold);
    for(int i = 0; i < n; i++){
        arr[i].order[0] = i + 1;
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1].gold == arr[i].gold){
            arr[i].order[0] = arr[i - 1].order[0];
        }
    }

    sort(arr, arr + n, CompareMedal);
    for(int i = 0; i < n; i++){
        arr[i].order[1] = i + 1;
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1].medal == arr[i].medal){
            arr[i].order[1] = arr[i - 1].order[1];
        }
    }

    sort(arr, arr + n, CompareGoldRate);
    for(int i = 0; i < n; i++){
        arr[i].order[2] = i + 1;
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1].goldRate == arr[i].goldRate){
            arr[i].order[2] = arr[i - 1].order[2];
        }
    }

    sort(arr, arr + n, CompareMedalRate);
    for(int i = 0; i < n; i++){
        arr[i].order[3] = i + 1;
    }
    for(int i = 1; i < n; i++){
        if(arr[i - 1].medalRate == arr[i].medalRate){
            arr[i].order[3] = arr[i - 1].order[3];
        }
    }

    sort(arr, arr + n, CompareID);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 4; j++){
            if(arr[i].bestOrder > arr[i].order[j]){
                arr[i].bestOrder = arr[i].order[j];
                arr[i].bestMethod = j + 1;
            }
        }
    }
}

int main(){
    int n, m;
    while(scanf("%d%d", &n, &m) != EOF){
        int gold, medal, people;
        for(int i = 0; i < n; i++){
            scanf("%d%d%d", &gold, &medal,&people);
            arr[i] = Nation(i, gold, medal, people);
        }
        Solve(n);
        for(int i = 0; i < m; i++){
            int index;
            scanf("%d", &index);
            printf("%d:%d\n", arr[index].bestOrder, arr[index].bestMethod);
        }
        printf("\n");
    }
    return 0;
}
