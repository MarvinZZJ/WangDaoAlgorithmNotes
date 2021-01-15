/*
习题4.4	浮点数加法（北京大学复试上机题）	
http://t.cn/Ai8I4v0j
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

string Add(string str1, string str2){
    string decimal1 = str1.substr(str1.find('.') + 1);
    string decimal2 = str2.substr(str2.find('.') + 1);
    //  小数对齐
    if(decimal1.size() < decimal2.size()){
        decimal1 += string(decimal2.size() - decimal1.size(), '0');
    }
    else{
        decimal2 += string(decimal1.size() - decimal2.size(), '0');
    }

    string integral1 = str1.substr(0, str1.find('.'));
    string integral2 = str2.substr(0, str2.find('.'));
    //  整数对齐
    if(integral1.size() < integral2.size()){
        integral1 = string(integral2.size() - integral1.size(), '0') + integral1;
    }
    else{
        integral2 = string(integral1.size() - integral2.size(), '0') + integral2;
    }
    //  小数部分相加
    int carry = 0;
    string decimal(decimal1.size(), ' ');
    for(int i = decimal.size() - 1; i >= 0; i--){
        int current = decimal1[i] - '0' + decimal2[i] - '0' + carry;
        carry = current / 10;
        decimal[i] = current % 10 + '0';
    }
    //  整数部分相加
    string integral(integral1.size(), ' ');
    for(int i = integral.size() - 1; i >= 0; i--){
        int current = integral1[i] - '0' + integral2[i] - '0' + carry;
        carry = current / 10;
        integral[i] = current % 10 + '0';
    }
    if(carry != 0){
        integral = string(1, carry + '0') + integral;  //  等价于integral = to_string(carry);  #此时需要添加头文件#include <cstring>
    }

    return (integral + '.' + decimal);
}

int main(){
    string str1, str2;
    while(cin >> str1 >> str2){
        cout << Add(str1, str2) << endl;
    }
    return 0;
}
