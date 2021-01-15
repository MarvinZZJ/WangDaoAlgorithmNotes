/*
例题4.2	密码翻译（北京大学复试上机题）	
http://t.cn/Ai8bGaIx
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i++){
            if(str[i] == 'z' || str[i] == 'Z'){
                str[i] -= 25;
            }
            else if((str[i] >= 'a' && str[i] <= 'y') ||
                    (str[i] >= 'A' && str[i] <= 'Y')){
                str[i]++;
            }
        }
        cout << str << endl;
    }
    return 0;
}
