/*
习题2.11坠落的蚂蚁（北京大学复试上机题）	
http://t.cn/E9dhoRA
*/

/*
除去A以外的所有蚂蚁记为B。B是一个整体。于是可以认为B中的蚂蚁相遇时不会交换速度。

B中的蚂蚁与A相遇时，仍然会交换速度。将B分为四类：A左侧向左走的记为LL，A左侧向右走的蚂蚁记为LR。同样的，规定RR和RL。
显然LL和RR永远不会与A相遇。对A有影响的只有LR和RL。
于是进一步的，情况简化为：A的左边只有向右走的蚂蚁LR，A的右边只有向左走的蚂蚁RL。

经过两次碰撞，A的速度就会被抵消，变为0. 因此，
① 若LR和RL的数目相同，则A最终会静止在木棍上；
② 若LR和RL数目不同，则无法全部相抵消。不妨设LR多一些，那么LR中就有那么一只蚂蚁C，
它的右边的LR的同伴都被抵消掉了，C撞到了A，A获得C的速度向右运动，直到坠落。这个过程的
时间等同于从C的初始位置向右走到尽头所需要的时间。
*/

//  代码一：
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

struct ant{
    int pos;
    int dir;
};

bool sortByPos(ant& a, ant& b){
    return (a.pos <= b.pos);
}
int main()
{
    int n;
    while(scanf("%d", &n) != EOF){
        if(n == 0)
            break;
        vector<ant> ants(n);
        int a_pos = 0, n_lr = 0, n_rl = 0;
        for(int i = 0; i < n; i++){
            cin >> ants[i].pos >> ants[i].dir;
            if(ants[i].dir == 0)
                a_pos = ants[i].pos;
        }
        //数rl与lr的个数；并以a——pos为基准，删除ll与rr的ant
        for(int i = ants.size() - 1; i >= 0; i--){
            if((ants[i].pos - a_pos) * ants[i].dir > 0){
                ants.erase(ants.begin() + i);
            }
            else if(ants[i].pos < a_pos){
                n_lr++;
            }
            else if(ants[i].pos > a_pos){
                n_rl++;
            }
        }
        //按pos排序
        sort(ants.begin(), ants.end(), sortByPos);
        //若左右相抵，则A不会坠落。否则，计算C的位置，得到结果。
        if(n_rl == n_lr){
            cout << "Cannot fall!" << endl;
            continue;
        }
        int c_index = (n_lr > n_rl) ? (n_lr - n_rl - 1) : (ants.size() - n_rl + n_lr);
        printf("%d\n", (n_lr > n_rl) ? (100 - ants[c_index].pos) : ants[c_index].pos);
    }
    return 0;
}

//  代码二：
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

struct Ant {
    int position;
    int direction;
};

const int MAXN = 100 + 10;

Ant ants[MAXN];

bool CompareByPosition(Ant x, Ant y){
    return x.position < y.position;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        vector<int> left, right;
        int pos;
        for(int i = 0; i < n; i++){
            scanf("%d%d", &ants[i].position, &ants[i].direction);
            if(ants[i].direction == 0){
                pos = ants[i].position;
            }
        }
        sort(ants, ants + n, CompareByPosition);
        for(int i = 0; i < n; i++){
            if(ants[i].position < pos && ants[i].direction == 1){
                left.push_back(ants[i].position);
            }
            else if(ants[i].position > pos && ants[i].direction == -1){
                right.push_back(ants[i].position);
            }
        }
        if(left.size() == right.size()){
            printf("Cannot fall!\n");
        }
        else if(left.size() > right.size()){
            printf("%d\n", 100 - left[left.size() - right.size() - 1]);
        }
        else{
            printf("%d\n", right[left.size()]);
        }
    }
    return 0;
}
