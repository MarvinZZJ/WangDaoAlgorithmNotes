/*
例题4.5	字母统计（上海交通大学复试上机题）	
http://t.cn/Ai8VB72e
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int number[26];

int main(){
    string str;
    while(cin >> str){
        memset(number, 0, sizeof(number));
        for(int i = 0; i < str.size(); i++){
            if(str[i] >= 'A' && str[i] <= 'Z'){
                number[str[i] - 'A']++;
            }
        }
        for(int i = 0; i < 26; i++){
            printf("%c:%d\n", 'A' + i, number[i]);
        }
    }
    return 0;
}
