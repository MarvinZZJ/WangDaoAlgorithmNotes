/*
例题4.6	Number Sequence	
http://acm.hdu.edu.cn/showproblem.php?pid=1711
*/

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000010;
const int MAXM = 10010;

int nextTable[MAXM];
int pattern[MAXN];
int text[MAXN];

void GetNext(int m){
    int i = 0;
    nextTable[0] = -1;
    int j = nextTable[0];
    while(i < m){
        if(j == -1 || pattern[i] == pattern[j]){
            i++;
            j++;
            nextTable[i] = j;
        }
        else{
            j = nextTable[j];
        }
    }
}

int KMP(int n, int m){
    int i = 0, j = 0;
    GetNext(m);
    while(i < n && j < m){
        if(j == -1 || text[i] == pattern[j]){
            i++;
            j++;
        }
        else{
            j = nextTable[j];
        }
    }
    if(j == m){
        return i - j + 1;
    }
    else{
        return -1;
    }
}

int main(){
    int num;
    cin >> num;
    while(num--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> text[i];
        }
        for(int j = 0; j < m; j++){
            cin >> pattern[j];
        }
        cout << KMP(n, m) << endl;
    }
    return 0;
}
