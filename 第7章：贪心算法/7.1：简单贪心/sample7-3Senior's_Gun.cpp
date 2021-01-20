/*
例题7.3	Senior's Gun	
http://acm.hdu.edu.cn/showproblem.php?pid=5281
*/

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAX = 1e5;

long long monster[MAX];
long long gun[MAX];

bool Compare(long long x, long long y){
    return x > y;
}

int main(){
    int caseNum;
    cin >> caseNum;
    while(caseNum--){
        int n, m;
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> gun[i];
        }
        for(int i = 0; i < m; i++){
            cin >> monster[i];
        }
        sort(gun, gun + n, Compare);
        sort(monster, monster + m);
        long long answer = 0;
        for(int i = 0; i < n && i < m; i++){
            if(gun[i] < monster[i]){
                break;
            }
            answer += (gun[i] - monster[i]);
        }
        cout << answer << endl;
    }
    return 0;
}
