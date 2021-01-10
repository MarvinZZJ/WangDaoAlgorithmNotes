/*
例题2.10	手机键盘（清华大学复试上机题）	
http://t.cn/E9ulcIc
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int keytab[26] = {1, 2, 3, 1, 2, 3, 1, 2, 3,
                        1, 2, 3, 1, 2, 3, 1, 2, 3, 4,
                        1, 2, 3, 1, 2, 3, 4};

int main(){
    string str;
    while(cin >> str){
        int time = 0;
        for(int i = 0; i < str.size(); i++){
            time += keytab[str[i] - 'a'];
            if(i != 0 && (str[i] - str[i - 1] == keytab[str[i] - 'a'] - keytab[str[i - 1] - 'a'])){
               time += 2;
               }
        }
        cout << time << endl;
    }
    return 0;
}
