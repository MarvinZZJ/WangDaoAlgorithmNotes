/*
例题4.7	Oulipo	
http://poj.org/problem?id=3461
*/

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXM = 10000 + 10;

int nextTable[MAXM];

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
    int sum = 0;
    int i = 0, j = 0;
    while(i < text.size()){
        if(j == -1 || text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            j = nextTable[j];
        }
        if(j == pattern.size()){
            j = nextTable[j];
            sum++;
        }
    }
    return sum;
}

int main(){
    int caseNum;
    scanf("%d", &caseNum);
    while(caseNum--){
        string text, pattern;
        cin >> text >> pattern;
        cout << KMP(text, pattern) << endl;
    }
    return 0;
}
