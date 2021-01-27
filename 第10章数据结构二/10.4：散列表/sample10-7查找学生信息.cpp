/*
例题10.7	查找学生信息（清华大学复试上机题）	
http://t.cn/AiCuVIuY
*/

#include <iostream>
#include <cstdio>
#include <map>
#include <string>

using namespace std;

int main(){
    int n;
    cin >> n;
    cin.ignore(1024, '\n');
    map<string, string> myMap;
    while(n--){
        string str;
        getline(cin, str);
        int pos = str.find(' ');
        string key = str.substr(0, pos);
        myMap[key] = str;
    }
    int m;
    cin >> m;
    while(m--){
        cin.ignore(1024, '\n');
        string key;
        cin >> key;
        map<string, string>::iterator it = myMap.find(key);
        if(it == myMap.end()){
            cout << "No Answer!" << endl;
        }
        else{
            cout << it->second << endl;
        }
    }
    return 0;
}
