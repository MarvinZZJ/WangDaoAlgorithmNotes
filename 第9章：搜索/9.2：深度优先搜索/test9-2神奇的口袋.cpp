/*
习题9.1	神奇的口袋（北京大学复试上机题）	
http://t.cn/Ai0u0GUz
*/

// 解法一：
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 20 + 5;

int goods[MAXN];

void DFS(int index, int sum, int n, int& answer){
    if(sum == 40){
        answer++;
        return;
    }
    for(int i = index; i < n; i++){
        if(sum + goods[i] > 40){
            continue;
        }
        DFS(i + 1, sum + goods[i], n, answer);
    }
    return;
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            scanf("%d", &goods[i]);
        }
        int answer = 0;
        DFS(0, 0, n, answer);
        cout << answer << endl;
    }
    return 0;
}



// 解法二：
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 25;

int goods[MAXN];

int DFS(int sum, int pos, int n){
    if(sum == 40){
        return 1;
    }
    else if(sum > 40 || pos == n){
        return 0;
    }
    else{
        return DFS(sum, pos + 1, n) + DFS(sum + goods[pos], pos + 1, n);
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            cin >> goods[i];
        }
        cout << DFS(0, 0, n) << endl;
    }
    return 0;
}
