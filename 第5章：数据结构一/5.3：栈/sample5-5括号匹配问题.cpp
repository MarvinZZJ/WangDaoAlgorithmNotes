/*
例题5.5	括号匹配问题	
http://ccnu.openjudge.cn/practice/1978/
*/

#include <iostream>
#include <cstdio>
#include <string>
#include <stack>

using namespace std;

int main(){
    string str;
    while(cin >> str){
        string answer(str.size(), ' ');
        stack<int> brackets;
        for(int i = 0; i < str.size(); i++){
            if(str[i] == '('){
                brackets.push(i);
            }
            else if(str[i] == ')'){
                if(brackets.empty()){
                    answer[i] = '?';
                }
                else{
                    brackets.pop();
                }
            }
        }
        while(!brackets.empty()){
            answer[brackets.top()] = '$';
            brackets.pop();
        }
        cout << str << endl;
        cout << answer << endl;
    }
    return 0;
}
