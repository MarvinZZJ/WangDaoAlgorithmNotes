/*
例题10.8	魔咒词典（浙江大学复试上机题）	
http://t.cn/AiCufczt
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
    string str;
    map<string, string> dictionary;
    while(getline(cin, str)){
        if(str == "@END@"){
            break;
        }
        int pos = str.find(']');
        string str1 = str.substr(0, pos + 1);
        string str2 = str.substr(pos + 2);
        dictionary[str1] = str2;
        dictionary[str2] = str1;
    }
    int n;
    cin >> n;
    cin.ignore(1024, '\n');
    string key;
    while(n--){
        getline(cin, key);
        map<string, string>::iterator it = dictionary.find(key);
        if(it != dictionary.end()){
            if(key[0] == '['){
                cout << it->second << endl;
            }
            else{
                string answer = it->second;
                answer = answer.substr(1, answer.size() - 2);
                cout << answer << endl;
            }
        }
        else{
            cout << "what?" << endl;
        }
    }
    return 0;
}
