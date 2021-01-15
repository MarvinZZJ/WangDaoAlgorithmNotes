/*
习题4.7	String Matching（上海交通大学复试上机题）	
https://www.nowcoder.com/questionTerminal/00438b0bc9384ceeb65613346b42e88a
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 1e6 + 10;

int nextTable[MAXN];

void GetNextTable(string pattern){
    int i = 0;
    nextTable[i] = -1;
    int j = nextTable[i];
    while(i < pattern.size()){
        if(j == -1 || pattern[i] == pattern[j]){
            i++;
            j++;
            nextTable[i] = j;
        }
        else{
            j = nextTable[j];
        }
    }
    return;
}

int KMP(string text, string pattern){
    GetNextTable(pattern);
    int i = 0, j = 0;
    int num = 0;
    while(i < text.size()){
        if(j == -1 || text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            j = nextTable[j];
        }
        if(j == pattern.size()){
            num++;
            j = nextTable[j];
        }
    }
    return num;
}

int main(){
    string text, pattern;
    while(cin >> text >> pattern){
        cout << KMP(text, pattern) << endl;
    }
    return 0;
}
