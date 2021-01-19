/*
习题6.12	数字阶梯求和（哈尔滨工业大学复试上机题）	
http://t.cn/Aipak8BQ
*/

//  方法一：定义一个大整型类
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1e4;

class BigInteger{

public:
    int digit[MAXN];
    int length;
    BigInteger();
    BigInteger operator=(string str);
    BigInteger operator+(const BigInteger& b);
    friend ostream& operator<<(ostream& out, const BigInteger& x);
};

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        digit[length++] = str[i] - '0';
    }
    return *this;
}

BigInteger BigInteger::operator+(const BigInteger& b){
    BigInteger answer;
    int carry = 0;
    for(int i = 0; i < length || i < b.length; i++){
        int current = carry + digit[i] + b.digit[i];
        answer.digit[answer.length++] = current % 10;
        carry = current / 10;
    }
    if(carry != 0){
        answer.digit[answer.length++] = carry;
    }
    return answer;
}

ostream& operator<<(ostream& out, const BigInteger& x){
    for(int i = x.length - 1; i >= 0; i--){
        out << x.digit[i];
    }
    return out;
}

int main(){
    int a, n;
    while(cin >> a >> n){
        BigInteger answer;
        for(int i = 1; i <= n; i++){
            BigInteger temp;
            temp = string(i, a + '0');
            answer = answer + temp;
        }
        cout << answer << endl;
    }
    return 0;
}




//  方法二：利用数组来实现
#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e4;

int arr[MAXN];  // 下标从小到大存储由低到高的数位

int main(){
    int a, n;
    while(scanf("%d%d", &a, &n) != EOF){
        int carry = 0;
        for(int i = 0; i < n; i++){
            arr[i] = 0;
            int current = carry + a * (n - i);
            arr[i] = current % 10;
            carry = current / 10;
        }
        if(carry != 0){
            arr[n++] = carry;
        }
        for(int i = n - 1; i >= 0; i--){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
