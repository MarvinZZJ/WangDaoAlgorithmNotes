/*
例题5.6	简单计算器（浙江大学复试上机题）	
http://t.cn/AiKoGS94
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>
#include <cctype>  // 调用isdigit()函数
using namespace std;

double GetNumber(string str, int& index){
    double res = 0;
    while(isdigit(str[index])){
        res = res * 10 + str[index] - '0';
        index++;
    }
    return res;
}

int Priority(char c){
    if(c == '#'){
        return 0;
    }
    else if(c == '$'){
        return 1;
    }
    else if(c == '+' || c == '-'){
        return 2;
    }
    else{
        return 3;
    }
}

double Calculate(double x, double y, char op){
    double res = 0;
    if(op == '+'){
        res = x + y;
    }
    else if(op == '-'){
        res = x - y;
    }
    else if(op == '*'){
        res = x * y;
    }
    else{
        res = x / y;
    }
    return res;
}

int main(){
    string str;
    while(getline(cin, str)){
        if(str == "0"){
            break;
        }
        stack<char> oper;
        stack<double> data;
        str += "$";
        oper.push('#');
        int index = 0;
        while(index < str.size()){
            if(str[index] == ' '){
                index++;
            }
            else if(isdigit(str[index])){
                double num = GetNumber(str, index);
                data.push(num);
            }
            else{
                if(Priority(oper.top()) < Priority(str[index])){
                    oper.push(str[index]);
                    index++;
                }
                else{
                    double y = data.top();
                    data.pop();
                    double x = data.top();
                    data.pop();
                    data.push(Calculate(x, y, oper.top()));
                    oper.pop();
                }
            }
        }
        printf("%.2f\n", data.top());
    }
    return 0;
}
