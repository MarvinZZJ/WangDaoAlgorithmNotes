/*
习题6.13	大整数的因子（北京大学复试上机题）	
http://t.cn/AipaFCJE
*/

//  方法一：
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 31;

int main(){
    string str;
    int c[MAXN];
    while(cin >> str){
        if(str[0] == '-'){
            break;
        }
        // 将字符串数字转化为整型数组，方便处理
        for(int i = 0; i < str.size(); i++){
            c[i] = str[i] - '0';
        }
        int hasFactor = 0;  // 判断是否有2~9中的某个因子
        for(int i = 2; i <= 9; i++){
            int remainder = 0;
            for(int j = 0; j < str.size(); j++){
                remainder *= 10;  // 原有余数进1位
                remainder += c[j];  // 加上新的个位
                if(remainder >= i){  // 余数大于除数
                    remainder %= i;
                }
            }
            if(remainder == 0){
                if(hasFactor++ != 0){
                    cout << " ";
                }
                cout << i;
            }
        }
        if(hasFactor == 0){
            cout << "none";
        }
        cout << endl;
    }
    return 0;
}


//  方法二： 定义大整数类BigInteger
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int MAXN = 30 + 1;

class BigInteger{

public:
    int digit[MAXN];
    int length;
    BigInteger();
    BigInteger(int x);
    BigInteger operator=(string str);
    BigInteger operator=(const BigInteger& b);
    bool operator<=(const BigInteger& b);
    BigInteger operator-(const BigInteger& b);
    BigInteger operator%(const BigInteger& b);

};

BigInteger::BigInteger(){
    memset(digit, 0, sizeof(digit));
    length = 0;
}

BigInteger::BigInteger(int x){
    memset(digit, 0, sizeof(digit));
    length = 0;
    if(x == 0){
        digit[length++] = x;
    }
    while(x != 0){
        digit[length++] = x % 10;
        x /= 10;
    }
}

BigInteger BigInteger::operator=(string str){
    memset(digit, 0, sizeof(digit));
    length = 0;
    for(int i = str.size() - 1; i >= 0; i--){
        digit[length++] = str[i] - '0';
    }
    return *this;
}

BigInteger BigInteger::operator=(const BigInteger& b){
    memset(digit, 0, sizeof(digit));
    length = b.length;
    for(int i = 0; i < b.length; i++){
        digit[i] = b.digit[i];
    }
    return *this;
}

bool BigInteger::operator<=(const BigInteger& b){
    if(length < b.length){
        return true;
    }
    else if(length > b.length){
        return false;
    }
    else{
        for(int i = length - 1; i >= 0; i--){
            if(digit[i] == b.digit[i]){
                continue;
            }
            else{
                return digit[i] < b.digit[i];
            }
        }
        return true;
    }
}

BigInteger BigInteger::operator-(const BigInteger& b){
    BigInteger answer;
    answer.length = length;
    int carry = 0;
    for(int i = 0; i < length; i++){
        int current = digit[i] - b.digit[i] - carry;
        if(current < 0){
            carry = 1;
            current = current + 10;
        }
        else{
            carry = 0;
        }
        answer.digit[i] = current;
    }
    while(answer.length > 1 && answer.digit[answer.length - 1] == 0){
        answer.length--;
    }
    return answer;
}


BigInteger BigInteger::operator%(const BigInteger& b){
    BigInteger remainder(0);
    BigInteger temp = b;
    for(int i = length - 1; i >= 0; i--){
        if(!(remainder.length == 1 && remainder.digit[0] == 0)){
            for(int j = remainder.length - 1; j >= 0; j--){
                remainder.digit[j + 1] = remainder.digit[j];
            }
            remainder.length++;
        }
        remainder.digit[0] = digit[i];
        while(temp <= remainder){
            remainder = remainder - temp;
        }
    }
    return remainder;
}

int main(){
    string str;
    while(cin >> str){
        if(str == "-1"){
            break;
        }
        BigInteger c;
        c = str;
        int hasFactor = 0;
        for(int i = 2; i <= 9; i++){
            BigInteger answer = c % BigInteger(i);
            if(answer.length == 1 && answer.digit[0] == 0){
                if(hasFactor++ != 0){
                    cout << ' ';
                }
                cout << i;
            }
        }
        if(hasFactor == 0){
            cout << "none";
        }
        cout << endl;
    }
    return 0;
}
