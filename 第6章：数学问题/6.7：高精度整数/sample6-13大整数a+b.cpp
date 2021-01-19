/*
例题6.13	a+b（华中科技大学复试上机题）	
http://t.cn/AipaWiSG
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 1000;

class BigInteger{

public:
    int digit[MAXN];
    int length;

    BigInteger();

    BigInteger operator=(string str);

    BigInteger operator+(const BigInteger& b);

    friend istream& operator>>(istream& in, BigInteger& x);
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
    BigInteger a, b;
    while(cin >> a >> b){
        cout << a + b << endl;
    }
    return 0;
}
