/*
例题2.3	对称平方数1（清华大学复试上机题）	
http://t.cn/E9lUYRn
*/
#include <iostream>
#include <cstdio>

using namespace std;

int Reverse(int x){
    int revex = 0;
    while(x){
        revex *= 10;
        revex += x % 10;
        x /= 10;
    }
    return revex;
}

int main(){
    for(int i = 0; i <= 256; i++){
        int sqrt = i * i;
        if(sqrt == Reverse(sqrt)){
            cout << i << endl;
        }
    }
}
