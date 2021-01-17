/*
例题6.9	质因数的个数（清华大学复试上机题）	
http://t.cn/Aip7J0Oo
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

const int MAXN = sqrt(1e9) + 1;
//bool isprime[MAXN];   //variable length array declaration not allowed at file scope

bool isPrime[35000];

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
    int n;
    while(cin >> n){
        int answer = 0;
        for(int i = 0; i < prime.size() && prime[i] < n; i++){
            int factor = prime[i];
            while(n % factor == 0){
                answer++;
                n /= factor;
            }
        }
        if(n > 1){
            answer++;
        }
        cout << answer << endl;
    }
    return 0;
}
