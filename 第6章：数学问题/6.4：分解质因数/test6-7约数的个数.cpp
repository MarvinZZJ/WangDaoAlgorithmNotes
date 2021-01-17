/*
习题6.7	约数的个数（清华大学复试上机题）	
http://t.cn/Aip7dTUp
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 4e4;

bool isPrime[MAXN];

vector<int> prime;

void Initial(){
    for(int i = 0; i < MAXN; i++){
        isPrime[i] = true;
    }
    isPrime[0] = isPrime[1] = false;
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

int NumberOfFactor(int n){
    vector<int> exponent;
    for(int i = 0; i < prime.size() && prime[i] <= n; i++){
        int current = 0;
        while(n % prime[i] == 0){
            current++;
            n /= prime[i];
        }
        exponent.push_back(current);
    }
    if(n > 1){
        exponent.push_back(1);
    }
    int answer = 1;
    for(int i = 0; i < exponent.size(); i++){
        answer *= (exponent[i] + 1);
    }
    return answer;
}

int main(){
    Initial();
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            int num;
            scanf("%d", &num);
            printf("%d\n", NumberOfFactor(num));
        }
    }
    return 0;
}
