/*
习题4.6	字符串匹配（北京航空航天大学复试上机题）	
https://www.nowcoder.com/questionTerminal/f7a070bc72e644d68d28fdacc9cc6792
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 1e3 + 10;

string strs[MAXN], pattern;

bool Equal(char x, char y){
    if(isalpha(x) && isalpha(y)){
        return toupper(x) == toupper(y);
    }
    else{
        return x == y;
    }
}

bool Match(string text, string pattern){
    int i = 0, j = 0;
    for(; i < text.size() && j < pattern.size(); i++, j++){
        bool flag = false;
        if(pattern[j] == '['){
            j++;
            while(pattern[j] != ']'){
                if(Equal(text[i], pattern[j])){
                    flag = true;
                }
                j++;
            }
        }
        else if(Equal(text[i], pattern[j])){
            flag = true;
        }
        else{
            return false;
        }
    }
    if(j == pattern.size()){
        return true;
    }
    else{
        return false;
    }
}

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        for(int i = 0; i < n; i++){
            cin >> strs[i];
        }
        cin >> pattern;
        for(int i = 0; i < n; i++){
            if(Match(strs[i], pattern)){
                cout << i + 1 << " " << strs[i] << endl;
            }
        }
    }
    return 0;
}
