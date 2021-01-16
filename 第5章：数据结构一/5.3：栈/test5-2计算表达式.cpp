/*
习题5.2	计算表达式（上海交通大学复试上机题）	
http://t.cn/AiKKJjJ5
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cctype>
#include <stack>

using namespace std;

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

double GetNumber(string str, int& index){
    int res = 0;
    while(isdigit(str[index])){
        res = res * 10 + str[index++] - '0';
    }
    return res;
}

double Calculate(double x, double y, char op){
    if(op == '+'){
        return x + y;
    }
    else if(op == '-'){
        return x - y;
    }
    else if(op == '*'){
        return x * y;
    }
    else{
        return x / y;
    }
}

int main(){
    string str;
    while(cin >> str){
        stack<char> oper;
        stack<double> data;
        oper.push('#');
        str += "$";
        int index = 0;
        while(index != str.size()){
            if(isdigit(str[index])){
                data.push(GetNumber(str, index));
            }
            else{
                if(Priority(oper.top()) < Priority(str[index])){
                    oper.push(str[index++]);
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
        cout << data.top() << endl;
    }
    return 0;
}
