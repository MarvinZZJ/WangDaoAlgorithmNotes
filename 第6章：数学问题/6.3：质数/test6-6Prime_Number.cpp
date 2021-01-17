/*
习题6.6	Prime Number（上海交通大学复试上机题）	
http://t.cn/AiCulrSh
*/

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1e5 + 10;

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

int main(){
    Initial();
    int k;
    while(cin >> k){
        cout << prime[k - 1] << endl;
    }
    return 0;
}
