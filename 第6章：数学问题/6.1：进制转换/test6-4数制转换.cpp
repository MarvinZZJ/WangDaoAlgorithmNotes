/*
习题6.4	数制转换（北京大学复试上机题）	
http://t.cn/AiCu6ne4
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

int CharToInt(char c){
    if(isdigit(c)){
        return c - '0';
    }
    else if(c >= 'a' && c <= 'f'){
        return c - 'a' + 10;
    }
    else{
        return c - 'A' + 10;
    }
}

char IntToChar(int data){
    if(data < 10){
        return data + '0';
    }
    else{
        return data + 'A' - 10;
    }
}

long long ConvertToTen(string num, int x){
    long long res = 0;
    for(int i = 0; i < num.size(); i++){
        res = res * x + CharToInt(num[i]);
    }
    return res;
}

void ConvertToTarget(long long num, int x){
    vector<char> answer;
    if(num == 0){
        answer.push_back('0');
    }
    else{
        while(num){
            answer.push_back(IntToChar(num % x));
            num /= x;
        }
    }
    for(int i = answer.size() - 1; i >= 0; i--){
        cout << answer[i];
    }
    cout << endl;
    return;
}

int main(){
    int a, b;
    string n;
    while(cin >> a >> n >> b){
        long long num = ConvertToTen(n, a);
        ConvertToTarget(num, b);
    }
    return 0;
}
