/*
例题2.9	剩下的树（清华大学复试上机题）	
http://t.cn/E9ufYo5
*/

//  法一：
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int MAXL = 10001;
int moveTree[MAXL];

int main(){
    int L, M;
    while(scanf("%d%d", &L, &M) != EOF){
        memset(moveTree, 0, sizeof(moveTree));
        while(M--){
            int left, right;
            scanf("%d%d", &left, &right);
            for(int i = left; i <= right; i++){
                moveTree[i]++;
            }
        }
        int sum = 0;
        for(int i = 0; i <= L; i++){
            if(!moveTree[i]){
                sum++;
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}

//  法二：
#include <iostream>
#include <cstdio>

using namespace std;

const int MAX_NUM = 10001;
bool tree[MAX_NUM];

int main()
{
    int L, m;
    while(scanf("%d %d", &L, &m) != EOF){
        for(int i = 0; i <= L; i++){
            tree[i] = true;
        }
        int tree_num = L + 1;
        int left, right;
        while(m--){
            scanf("%d %d", &left, &right);
            for(int i = left; i <= right; i++){
                if(tree[i]){
                    tree[i] = false;
                    tree_num--;
                }
            }
        }
        cout << tree_num << endl;
    }
    return 0;
}
