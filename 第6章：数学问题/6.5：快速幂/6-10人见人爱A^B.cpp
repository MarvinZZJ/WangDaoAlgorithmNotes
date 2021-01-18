/*
例题6.10	人见人爱A^B	
http://acm.hdu.edu.cn/showproblem.php?pid=2035
*/

#include <iostream>
#include <cstdio>

using namespace std;

// 求a^b的后三位数(快速幂的变形)
int FastExponentiation(int a, int b, int mod){
    int answer = 1;
    while(b != 0){  // 不断将b由地位到高位转化为二进制数
        if(b % 2 == 1){  // 如当第k位前二进制位为1，代表要累乘a的2^(k-1)次幂
            answer *= a;
            answer %= mod;  // 只取后三位
        }
        b /= 2;
        a *= a;  // a不断平方
        a %= mod;  // 只取后三位
    }
    return answer;
}

int main()
{
    int a, b;
    while(cin >> a >> b){
        if(a == 0 && b == 0){
            break;
        }
        cout << FastExponentiation(a, b, 1000) << endl;
    }
    return 0;
}
