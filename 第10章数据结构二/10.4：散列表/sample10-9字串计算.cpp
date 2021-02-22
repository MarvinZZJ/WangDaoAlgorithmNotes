/*
例题10.9	字串计算（北京大学复试上机题）	
http://t.cn/AiCuJtI5
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        map<string, int> myMap;
        for(int i = 0; i < str.size(); i++){
            for(int j = i; j < str.size(); j++){
                myMap[str.substr(i, j - i + 1)]++;
            }
        }
        map<string, int>::iterator it = myMap.begin();
        for(; it != myMap.end(); it++){
            if(it->second > 1){
                cout << it->first << " " << it->second << endl;
            }
        }
    }
    return 0;
}
