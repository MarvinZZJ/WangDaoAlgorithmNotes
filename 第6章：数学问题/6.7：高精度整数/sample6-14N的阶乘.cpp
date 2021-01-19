/*
例题6.14	N的阶乘（清华大学复试上机题）	
http://t.cn/AipaBKQJ
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 10000;

class BigInteger{

public:
    int digit[MAXN];
    int length;
    BigInteger();
    BigInteger(int x);
    BigInteger operator=(string str);
    BigInteger operator*(const BigInteger& b);
    friend istream& operator>>(istream& in, BigInteger& x);
    friend ostream& operator<<(ostream& out, const BigInteger& x);
};

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        length++;
    }
    while(x != 0){
        digit[length++] = (x % 10);
        x /= 10;
    }
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        digit[length++] = str[i];
    }
    return *this;
}

BigInteger BigInteger::operator*(const BigInteger& b){
    BigInteger answer;
    answer.length = length + b.length;
    for(int i = 0; i < length; i++){
        for(int j = 0; j < b.length; j++){
            answer.digit[i + j] += (digit[i] * b.digit[j]);
        }
    }
    for(int i = 0; i < answer.length; i++){
        answer.digit[i + 1] += (answer.digit[i] / 10);
        answer.digit[i] %= 10;
    }
    while(answer.length > 1 && answer.digit[answer.length - 1] == 0){
        answer.length--;
    }
    return answer;
}

istream& operator>>(istream& in, BigInteger& x){
    string str;
    in >> str;
    x = str;
    return in;
}

ostream& operator<<(ostream& out, const BigInteger& x){
    for(int i = x.length - 1; i >= 0; i--){
        out << x.digit[i];
    }
    return out;
}

int main(){
    int n;
    while(cin >> n){
        BigInteger answer(1);
        for(int i = 2; i <= n; i++){
            answer = answer * BigInteger(i);
        }
        cout << answer << endl;
    }
    return 0;
}
