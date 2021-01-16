/*
例题6.6	最小公倍数	
http://acm.hdu.edu.cn/showproblem.php?pid=1108
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

int LCM(int a, int b){
    int gcd = GCD(a, b);
    return a * b / gcd;
}

int main(){
    int a, b;
    while(cin >> a >> b){
        cout << LCM(a, b) << endl;
    }
    return 0;
}
