/*
习题4.5	后缀字符串排序（上海交通大学复试上机题）	
https://www.nowcoder.com/questionTerminal/f89f96ea3145418b8e6c3eb75773f65a
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        string strs[str.size()];
        for(int i = 0; i < str.size(); i++){
            strs[i] = str.substr(i);
        }
        sort(strs, strs + str.size());
        for(int i = 0; i < str.size(); i++){
            cout << strs[i] << endl;
        }
    }
    return 0;
}
