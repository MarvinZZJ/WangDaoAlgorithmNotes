/*
习题4.2	单词替换（北京大学复试上机题）	
http://t.cn/Ai8Iycp6
*/

//  方法一：不推荐
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    string str, will_instead, instead;
    while(getline(cin, str)){
        getline(cin, will_instead);
        getline(cin, instead);
        int len_will = will_instead.size();
        int loc = 0;
        while(loc < str.size()){
            loc = str.find(will_instead, loc);
            if(loc == -1){ // 没有匹配的字符串
                break;
            }else if(loc == 0 && str[loc + len_will] == ' '){ // 匹配，且是str中第一个单词
                str.erase(loc, len_will);
                str.insert(loc, instead);
                loc = loc + instead.size();
            }else if(loc + len_will == str.size() && str[loc - 1] == ' '){  //匹配，且是最后一个词
                str.erase(loc, len_will);
                str.append(instead);
            }else if(str[loc - 1] == ' ' && str[loc + len_will] == ' ' ){ //匹配，且是一个词
                str.erase(loc, len_will);
                str.insert(loc, instead);
                loc = loc + instead.size();
            }else{ // 匹配，但不是一个词
                loc = loc + len_will;
            }
        }
        cout << str << endl;
    }
    return 0;
}


//  方法二：
#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string line;
    while(getline(cin, line)){
        string a, b;
        cin >> a >> b;
        stringstream strStream; 
        strStream << line;    // 等价于stringstream strStream(line);
        string str;
        while(strStream >> str){
            if(str == a){
                cout << b << " ";
            }
            else{
                cout << a << " ";
            }
        }
        cout << endl;
    }
    return 0;
}
