/*
习题4.3	首字母大写（北京大学复试上机题）	
http://t.cn/Ai8I2hco
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main(){
    string str;
    while(getline(cin, str)){
        for(int i = 0; i < str.size(); i++){
            if(i == 0 || str[i - 1] == ' ' || str[i - 1] == '\n' || str[i - 1] == '\r' || str[i - 1] == '\t'){
                if(str[i] >= 'a' && str[i] <= 'z'){
                    str[i] += ('A' - 'a');  // 等价于str[i] = toupper(str[i]);
                }
            }
        }
        cout << str << endl;
    }
    return 0;
}
