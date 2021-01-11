/*
例题2.11	XXX定律（浙江大学复试上机题）	
http://t.cn/E937wDs
*/

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while(cin >> n){
        if(n == 0){
            break;
        }
        int step = 0;
        while(n != 1){
            step++;
            if(n % 2 != 0){
                n = n * 3 + 1;
            }
            n /= 2;
        }
        cout << step << endl;
    }
    return 0;
}
