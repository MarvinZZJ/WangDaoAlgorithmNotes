/*
最大公约数（哈尔滨工业大学复试上机题）	
http://t.cn/AiCuWLTS
*/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int GCD(int a, int b){
    if(a < b){
        swap(a, b);
    }
    if(b == 0){
        return a;
    }
    else{
        return GCD(b, a % b);
    }
}

int main(){
    int a, b;
    while(cin >> a >> b){
        cout << GCD(a, b) << endl;
    }
    return 0;
}
