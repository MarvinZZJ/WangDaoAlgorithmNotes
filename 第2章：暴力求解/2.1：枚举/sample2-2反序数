/*
例题2.2	反序数（清华大学复试上机题）	
http://t.cn/E9WBrut
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
    for(int i = 1000; i < 1200; i++){
        if(i * 9 == Reverse(i)){
            cout << i << endl; // printf("%d/n", i);
        }
    }
}
