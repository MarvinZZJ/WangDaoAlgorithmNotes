/*
习题6.9	求root(N,K)（清华大学复试上机题）	
http://t.cn/AipAw4B1
*/

#include <iostream>
#include <cstdio>

using namespace std;

int FastExponentiation(int x, int y, int mod){
    int res = 1;
    while(y != 0){
        if(y % 2 == 1){
            res *= x;
            res %= mod;
        }
        y /= 2;
        x *= x;
        x %= mod;
    }
    return res;
}

int main(){
    int x, y, k;
    while(cin >> x >> y >> k){
        int res = FastExponentiation(x, y, k - 1);
        if(res == 0){
            res = k - 1;
        }
        cout << res << endl;
    }
    return 0;
}
