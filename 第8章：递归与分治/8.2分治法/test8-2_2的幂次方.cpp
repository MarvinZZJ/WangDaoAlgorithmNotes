/*
习题8.3	2的幂次方（上海交通大学复试上机题）	
http://suo.im/5D5hnX
*/

// 方法一：利用stack存放二次幂
#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

string pow2(int n){
    // 转换为二进制
    stack<int> power;
    int exponent = 0;
    while(n != 0){
        if(n % 2 == 1){
            power.push(exponent);
        }
        n /= 2;
        exponent++;
    }
    string answer = "";
    while(!power.empty()){
        if(power.top() == 0){
            answer += "2(0)";
        }
        else if(power.top() == 1){
            answer += "2";
        }
        else{
            answer += ("2(" + pow2(power.top()) + ")");
        }
        power.pop();
        if(!power.empty()){
            answer += "+";
        }
    }
    return answer;
}


// 方法二：利用数组存放二次幂
#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

const int MAX = 30;

string pow2(int n){
    bool power[MAX];
    memset(power, false, sizeof(power));
    int index = 0, counter = 0;  // counter用于后面判断是否需要输出“+”
    // 转化为二进制数，低位保存在低位下标
    while(n != 0){
        if(n % 2 == 1){
            power[index] = true;
            counter++;
        }
        n /= 2;
        index++;
    }
    string answer = "";
    for(int i = index - 1; i >= 0; i--){
        if(power[i] == true){
            if(i == 0){
                answer += "2(0)";
            }
            else if(i == 1){
                answer += "2";
            }
            else{
                answer += ("2(" + pow2(i) + ")");
            }
            if(--counter > 0){
            answer += "+";
            }
        }
    }
    return answer;
}

int main(){
    int n;
    while(cin >> n){
        cout << pow2(n) << endl;
    }
    return 0;
}
