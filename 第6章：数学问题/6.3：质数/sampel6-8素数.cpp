/*
例题6.8	素数	
http://t.cn/AiCulqtW
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e4 + 10;

bool isPrime[MAXN];
vector<int> prime;

void Initial(){
    for(int i = 0; i < MAXN; i++){
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for(int i = 2; i < MAXN; i++){
        if(isPrime[i]){
            prime.push_back(i);
            for(int j = i * i; j < MAXN; j += i){
                isPrime[j] = false;
            }
        }
    }
    return;
}

int main(){
    Initial();
    int n;
    while(scanf("%d", &n) != EOF){
        bool hasOutput = false;
        for(int i = 0; i < prime.size() && prime[i] < n; i++){
            if(prime[i] % 10 == 1){
                printf("%d ", prime[i]);
                hasOutput = true;
            }
        }
        if(hasOutput){
            printf("\n");
        }
        else{
            printf("-1\n");
        }
    }
    return 0;
}
