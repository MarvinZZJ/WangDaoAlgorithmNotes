/*
例题8.1	n的阶乘（清华大学复试上机题）	
http://t.cn/Ai0ocOUY
*/

#include <iostream>
#include <cstdio>

using namespace std;

long long Factorial(int n){
    if(n == 0){
        return 1;
    }
    else{
        return n * Factorial(n - 1);
    }
}

int main(){
    int n;
    while(cin >> n){
        cout << Factorial(n) << endl;
    }
    return 0;
}
