/*
例题5.4	Zero-complexity Transposition（上海交通大学复试上机题）	
http://t.cn/AiKa20bt
*/

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    stack<long long> sequence;
    int n;
    while(scanf("%d", &n) != EOF){
        long long num;
        for(int i = 0; i < n; i++){
            scanf("%I64d", &num);  // 此为Windows系统下的输入格式；Linux系统下用scanf("%lld", &num);
            sequence.push(num);
        }
        while(!sequence.empty()){
            printf("%I64d ", sequence.top());
            sequence.pop();
        }
        printf("\n");
    }
    return 0;
}
