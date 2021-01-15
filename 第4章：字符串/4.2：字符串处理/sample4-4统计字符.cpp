/*
例题4.4	统计字符（浙江大学复试上机题）	
http://t.cn/Ai8fvq4I
*/

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

int number[128];

int main(){
    string str1,str2;
    while(getline(cin, str1)){
        if(str1 == "#"){
            break;
        }
        getline(cin, str2);
        memset(number, 0, sizeof(number));
        for(int i = 0; i < str2.size(); i++){
            number[str2[i]]++;
        }
        for(int i = 0; i < str1.size(); i++){
            printf("%c %d\n", str1[i], number[str1[i]]);
        }
    }
    return 0;
}
